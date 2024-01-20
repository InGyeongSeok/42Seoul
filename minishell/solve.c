/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:43:10 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 18:15:04 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_fds(t_fds fds)
{
	if (fds.in_fd > 2)
		close(fds.in_fd);
	if (fds.out_fd > 2)
		close(fds.out_fd);
	return (1);
}

void	exe_failed(const char *cmd)
{
	write(2, "gsh: ", 7);
	while (*cmd)
		write(2, cmd++, 1);
	write(2, ": command not found\n", 20);
	exit(127);
}

int	solve_cmd(char **cmd_list, char **envp)
{
	char	*cmd;
	char	**path;
	int		i;

	cmd = cmd_list[0];
	while (*cmd)
		if (*cmd++ == '/')
			return (0);
	cmd = my_getenv(envp, "PATH");
	path = ft_split(cmd, ':');
	i = -1;
	while (path && path[++i])
	{
		cmd = my_pathjoin(path[i], cmd_list[0]);
		if (0 == access(cmd, F_OK))
		{
			free(cmd_list[0]);
			cmd_list[0] = cmd;
			break ;
		}
		free(cmd);
	}
	free_split(path);
	return (1);
}

void	exe_cmd(char **cmd_list, char **envp)
{
	int			is_no_slash;
	const char	*cmd = cmd_list[0];

	is_no_slash = solve_cmd(cmd_list, envp);
	if (execve(cmd_list[0], cmd_list, envp) < 0)
	{
		ft_putstr_fd("gsh: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (is_no_slash || access(cmd, F_OK) < 0)
		{
			if (is_no_slash)
				ft_putstr_fd("command not found\n", STDERR_FILENO);
			else
				perror(NULL);
			exit(127);
		}
		is_no_slash = open(cmd, O_DIRECTORY);
		if (is_no_slash < 0 && errno == ENOTDIR)
			ft_putstr_fd(strerror(EACCES), STDERR_FILENO);
		else
			ft_putstr_fd("is a directory", STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
		exit(126);
	}
}
