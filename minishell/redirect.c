/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:51:12 by seonglim          #+#    #+#             */
/*   Updated: 2023/10/29 07:36:50 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redir_errhand(int *fd)
{
	ft_putstr_fd("gsh: syntax error near unexpected token `newline'\n", 2);
	*fd = -258;
	exit_code(258, 1);
}

void	stdin_redirect(int *fd, char **cmd_list, int *i)
{
	int	j;

	if (*fd > 2)
		close(*fd);
	if (!cmd_list[*i])
		return (redir_errhand(fd));
	*fd = open(cmd_list[*i], O_RDONLY);
	if (*fd < 0)
	{
		perror(sum_msg("gsh: ", cmd_list[*i], 0));
		exit_code(EXIT_FAILURE, 1);
		return ;
	}
	free(cmd_list[*i - 1]);
	free(cmd_list[*i]);
	j = --*i;
	while (1)
	{
		cmd_list[j] = cmd_list[j + 2];
		if (!cmd_list[j++ + 2])
			break ;
	}
}

void	stdout_redirect(int *fd, char **cmd_list, int *i, int open_flag)
{
	int	j;

	if (*fd > 2)
		close(*fd);
	if (!cmd_list[*i])
		return (redir_errhand(fd));
	*fd = open(cmd_list[*i], open_flag, 0644);
	if (*fd < 0)
	{
		perror(sum_msg("gsh: ", cmd_list[*i], 0));
		exit_code(EXIT_FAILURE, 1);
		return ;
	}
	free(cmd_list[*i - 1]);
	free(cmd_list[*i]);
	j = --*i;
	while (1)
	{
		cmd_list[j] = cmd_list[j + 2];
		if (!cmd_list[j++ + 2])
			break ;
	}
}

void	heredoc_redirect(int *fd, char **cmd_list, int *i)
{
	int	j;

	if (*fd > 2)
		close(*fd);
	if (!cmd_list[*i])
		return (redir_errhand(fd));
	*fd = here_doc(cmd_list[*i]);
	free(cmd_list[*i - 1]);
	free(cmd_list[*i]);
	j = --*i;
	while (1)
	{
		cmd_list[j] = cmd_list[j + 2];
		if (!cmd_list[j++ + 2])
			break ;
	}
}

t_fds	change_redirect(char **cmd_list)
{
	int		i;
	t_fds	fds;

	fds.in_fd = READ;
	fds.out_fd = WRITE;
	i = 0;
	while (cmd_list[i++])
	{
		if (0 == ft_strncmp(cmd_list[i - 1], "<", 2))
			stdin_redirect(&fds.in_fd, cmd_list, &i);
		else if (0 == ft_strncmp(cmd_list[i - 1], ">", 2))
			stdout_redirect(&fds.out_fd, cmd_list, &i, 1 | O_CREAT | O_TRUNC);
		else if (0 == ft_strncmp(cmd_list[i - 1], ">>", 3))
			stdout_redirect(&fds.out_fd, cmd_list, &i, 1 | O_CREAT | O_APPEND);
		else if (0 == ft_strncmp(cmd_list[i - 1], "<<", 3))
			heredoc_redirect(&fds.in_fd, cmd_list, &i);
		if (fds.in_fd < 0 || fds.out_fd < 0)
			break ;
	}
	return (fds);
}
