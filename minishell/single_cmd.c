/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:41:55 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/18 02:54:46 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_single_sub(int *isquote, int *isdouble, char c)
{
	if (*isquote)
	{
		if (c == '\'' && !*isdouble)
			*isquote = 0;
		if (c == '\"' && *isdouble)
		{
			*isquote = 0;
			*isdouble = 0;
		}
	}
	else
	{
		*isquote = 1;
		if (c == '\"')
			*isdouble = 1;
	}
}

int	is_single_cmd(char *str)
{
	char	c;
	int		isquote;
	int		isdouble;

	isquote = 0;
	isdouble = 0;
	while (*str)
	{
		c = *str++;
		if (c == '\'' || c == '\"')
			is_single_sub(&isquote, &isdouble, c);
		else if (c == '|' && !isquote)
			return (0);
	}
	return (1);
}

static void	single_exit(int status)
{
	if (WIFEXITED(status))
		exit_code(WEXITSTATUS(status), 1);
	else if (WIFSIGNALED(status))
	{
		exit_code(WTERMSIG(status) + 128, 1);
		printf("\n");
	}
}

static void	single_fork(char **split, char **envp, t_fds fds, pid_t pid)
{
	int	status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (fds.in_fd > 2 && (dup2(fds.in_fd, READ) < 0 || close(fds.in_fd)))
			exit(EXIT_FAILURE);
		if (fds.out_fd > 2 && (dup2(fds.out_fd, 1) < 0 || close(fds.out_fd)))
			exit(EXIT_FAILURE);
		exe_cmd(split, envp);
	}
	else if (pid > 0)
	{
		close_fds(fds);
		free_split(split);
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		signal(SIGINT, sigint_handler);
		single_exit(status);
	}
}

void	single_cmd(char *line, char ***my_envp)
{
	char	**split;
	t_fds	fds;

	if (is_all_ws(line))
		return ;
	split = cmd_split(line, *my_envp);
	if (!split)
		return ;
	fds = change_redirect(split);
	if (!*split && close_fds(fds))
		return (free_split(split));
	if (!ft_strncmp(*split, "exit", 5))
		ft_putstr_fd("exit\n", 2);
	if (fds.in_fd < 0 || fds.out_fd < 0 || is_builtin_sg(split, my_envp, fds))
	{
		close_fds(fds);
		free_split(split);
		return ;
	}
	single_fork(split, *my_envp, fds, 0);
}
