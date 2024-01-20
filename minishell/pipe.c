/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:36:30 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 18:36:07 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_sub1(int infd, t_fds fds, char **split)
{
	close_fds(fds);
	if (infd > 0)
		close(infd);
	free_split(split);
}

static void	run_pipe_fork_sub(int infd, char **split, char ***myenvp, t_fds fds)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (dup2(infd, STDIN_FILENO) < 0 || close(infd) < 0)
		exit(EXIT_FAILURE);
	if (fds.in_fd > 2 && (dup2(fds.in_fd, 0) < 0 || close(fds.in_fd)))
		exit(EXIT_FAILURE);
	if (fds.out_fd > 2 && (!dup2(fds.out_fd, 1) || close(fds.out_fd)))
		exit(EXIT_FAILURE);
	if (is_builtin(split, myenvp, (t_fds){READ, WRITE}))
		exit(exit_code(0, 0));
	exe_cmd(split, *myenvp);
}

static pid_t	run_pipe_fork(int infd, char **split, char ***myenvp, t_fds fds)
{
	pid_t	pid;

	pid = fork();
	if (0 == pid)
		run_pipe_fork_sub(infd, split, myenvp, fds);
	else if (pid > 0)
	{
		close_fds(fds);
		free_split(split);
	}
	return (pid);
}

void	run_child(int infd, char **cmd_lines, pid_t *pid, char ***my_envp)
{
	int		fd[2];
	char	**split;
	t_fds	fds;

	split = cmd_split(*cmd_lines, *my_envp);
	if (!split || pipe(fd) < 0)
		return ;
	fds = change_redirect(split);
	if (!*split || fds.in_fd < 0 || fds.out_fd < 0)
		return (pipe_sub1(infd, fds, split));
	*pid = fork();
	if (*pid > 0)
	{
		close(fd[WRITE]);
		run_pipe(fd[READ], cmd_lines + 1, pid, my_envp);
		run_child_sub(fd, fds, infd, 1);
		free_split(split);
	}
	else if (0 == *pid)
	{
		run_child_start();
		run_child_sub(fd, fds, infd, 0);
		run_child_end(split, my_envp, (t_fds){READ, WRITE});
		exe_cmd(split, *my_envp);
	}
}

void	run_pipe(int infd, char **cmd_lines, pid_t *pid, char ***my_envp)
{
	char	**split;
	t_fds	fds;

	if (!*(cmd_lines + 1))
	{
		split = cmd_split(*cmd_lines, *my_envp);
		if (!split)
			return ;
		fds = change_redirect(split);
		if (!*split || fds.in_fd < 0 || fds.out_fd < 0)
			return (pipe_sub1(infd, fds, split));
		*pid = run_pipe_fork(infd, split, my_envp, fds);
	}
	else
		run_child(infd, cmd_lines, pid, my_envp);
}
