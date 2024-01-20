/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 06:17:40 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 16:33:17 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_inout(t_fds fds, int is_set)
{
	static t_fds	backup_fds;

	if (is_set)
	{
		backup_fds.in_fd = dup(STDIN_FILENO);
		backup_fds.out_fd = dup(STDOUT_FILENO);
		if (fds.in_fd > 2 && (dup2(fds.in_fd, STDIN_FILENO) < 0
				|| close(fds.in_fd)))
			return ;
		if (fds.out_fd > 2 && (dup2(fds.out_fd, STDOUT_FILENO) < 0
				|| close(fds.out_fd)))
			return ;
	}
	else
	{
		if (dup2(backup_fds.in_fd, STDIN_FILENO) < 0)
			return ;
		if (dup2(backup_fds.out_fd, STDOUT_FILENO) < 0)
			return ;
		close(backup_fds.in_fd);
		close(backup_fds.out_fd);
	}
}

int	is_builtin_sg(char **split, char ***my_envp, t_fds fds)
{
	if (0 == ft_strncmp(split[0], "echo", 5))
		;
	else if (0 == ft_strncmp(split[0], "cd", 3))
		;
	else if (0 == ft_strncmp(split[0], "pwd", 4))
		;
	else if (0 == ft_strncmp(split[0], "export", 7))
		;
	else if (0 == ft_strncmp(split[0], "unset", 6))
		;
	else if (0 == ft_strncmp(split[0], "env", 4))
		;
	else if (0 == ft_strncmp(split[0], "exit", 5))
		;
	else
		return (0);
	is_builtin(split, my_envp, fds);
	return (1);
}

int	is_builtin(char **split, char ***my_envp, t_fds fds)
{
	change_inout(fds, 1);
	if (0 == ft_strncmp(split[0], "echo", 5))
		builtin_echo(split);
	else if (0 == ft_strncmp(split[0], "cd", 3))
		builtin_cd(split, my_envp);
	else if (0 == ft_strncmp(split[0], "pwd", 4))
		builtin_pwd(split, my_envp);
	else if (0 == ft_strncmp(split[0], "export", 7))
		builtin_export(split, my_envp, 0);
	else if (0 == ft_strncmp(split[0], "unset", 6))
		builtin_unset(split, my_envp);
	else if (0 == ft_strncmp(split[0], "env", 4))
		builtin_env(split, my_envp);
	else if (0 == ft_strncmp(split[0], "exit", 5))
		builtin_exit(split);
	else
	{
		change_inout(fds, 0);
		return (0);
	}
	change_inout(fds, 0);
	return (1);
}

char	*my_pathjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(s1_len + s2_len + 1 + 1);
	if (ptr)
	{
		ft_strlcpy(ptr, s1, s1_len + 1);
		ptr[s1_len] = '/';
		ft_strlcpy(ptr + s1_len + 1, s2, s2_len + 1);
	}
	return (ptr);
}

const char	*sum_msg(const char *s1, const char *s2, int flag)
{
	static char	*buf;
	int			i;
	int			j;

	free(buf);
	buf = NULL;
	if (flag)
		return (NULL);
	buf = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (*s1)
		buf[i++] = *s1++;
	j = 0;
	while (*s2)
		buf[i + j++] = *s2++;
	buf[i + j] = '\0';
	return (buf);
}
