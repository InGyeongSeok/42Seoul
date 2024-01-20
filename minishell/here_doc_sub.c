/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:34:17 by seonglim          #+#    #+#             */
/*   Updated: 2023/10/29 07:39:13 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_doc_parent(pid_t pid)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, sigint_handler);
	return (status);
}

int	here_doc_input(char *limiter, int wr_fd)
{
	pid_t	pid;
	char	*line;

	pid = fork();
	if (0 == pid)
	{
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			line = readline("> ");
			if (!line || 0 == ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
				break ;
			ft_putstr_fd(line, wr_fd);
			free(line);
			ft_putstr_fd("\n", wr_fd);
		}
		free(line);
		exit(EXIT_SUCCESS);
	}
	else if (pid > 0)
		return (here_doc_parent(pid));
	return (0);
}

int	here_doc(char *limiter)
{
	int		wr_fd;
	int		rd_fd;
	int		status;

	unlink("/tmp/gsh_heredoc");
	wr_fd = open("/tmp/gsh_heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (wr_fd < 0)
		exit_code(EXIT_FAILURE, 1);
	rd_fd = open("/tmp/gsh_heredoc", O_RDONLY);
	if (rd_fd < 0 || unlink("/tmp/gsh_heredoc") < 0)
		exit_code(EXIT_FAILURE, 1);
	status = here_doc_input(limiter, wr_fd);
	close(wr_fd);
	if (WIFSIGNALED(status))
	{
		close(rd_fd);
		rd_fd = -2;
		printf("\n");
		exit_code(EXIT_FAILURE, 1);
	}
	return (rd_fd);
}
