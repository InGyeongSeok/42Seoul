/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:21:28 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 16:31:11 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_all_ws(char *str)
{
	char	c;

	while (*str)
	{
		c = *str++;
		if (!(c >= '\t' && c <= '\r') && c != ' ')
			return (0);
	}
	return (1);
}

int	is_right_pipe(char *line)
{
	int		error;
	char	c;

	error = 1;
	while (*line)
	{
		c = *line;
		if (c == '|')
		{
			if (error == 1)
				return (!exit_code(258, 1));
			error = 1;
		}
		else if (!(c >= '\t' && c <= '\r') && c != ' ')
			error = 0;
		++line;
	}
	if (error)
		exit_code(258, 1);
	return (!error);
}

int	wait_all(pid_t last_pid)
{
	pid_t	end_pid;
	int		status;
	int		retval;

	if (last_pid == -10)
	{
		exit_code(0, 1);
		return (-10);
	}
	while (1)
	{
		end_pid = wait(&status);
		if (-1 == end_pid)
			return (retval);
		if (end_pid == last_pid)
			retval = status;
	}
}

t_pvec	make_my_envp(char **envp)
{
	t_pvec		my_envp;
	t_str		env_str;
	int			i;

	my_envp = make_pvec();
	while (*envp)
	{
		env_str = make_str();
		i = 0;
		while ((*envp)[i])
			str_push(&env_str, (*envp)[i++]);
		pvec_push(&my_envp, env_str.s);
		envp++;
	}
	return (my_envp);
}

char	*my_getenv(char **my_envp, const char *name)
{
	size_t			namelen;
	unsigned char	code;
	static char		buf[4];
	int				len;

	if (0 == ft_strncmp(name, "?", 2))
	{
		code = exit_code(0, 0);
		len = (code / 100 != 0) + (code / 10 != 0) + 1;
		buf[len] = '\0';
		while (len > 0)
		{
			buf[--len] = code % 10 + '0';
			code /= 10;
		}
		return (buf);
	}
	namelen = ft_strlen(name);
	while (*my_envp)
	{
		if (0 == ft_strncmp(*my_envp, sum_msg(name, "=", 0), namelen + 1))
			return ((*my_envp) + namelen + 1);
		++my_envp;
	}
	return (NULL);
}
