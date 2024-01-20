/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:09:56 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 18:37:49 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_child_start(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	run_child_end(char **split, char ***my_envp, t_fds fds)
{
	if (is_builtin(split, my_envp, fds))
		exit(exit_code(0, 0));
}

void	run_child_sub(int fd[2], t_fds fds, int infd, int flag)
{
	if (flag)
	{
		close(fd[READ]);
		close_fds(fds);
	}
	else
	{
		close(fd[READ]);
		if (dup2(infd, READ) < 0 || dup2(fd[WRITE], WRITE) < 0)
			exit(EXIT_FAILURE);
		if (infd > 0)
			close(infd);
		close(fd[WRITE]);
		if (fds.in_fd > 2 && (dup2(fds.in_fd, READ) < 0 || close(fds.in_fd)))
			exit(EXIT_FAILURE);
		if (fds.out_fd > 2 && (dup2(fds.out_fd, 1) < 0 || close(fds.out_fd)))
			exit(EXIT_FAILURE);
	}
}
