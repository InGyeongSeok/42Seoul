/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:52:09 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 17:46:31 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_pipe_sub1(t_c *var, char c)
{
	if (var->isquote)
	{
		if (c == '\'' && !var->isdouble)
			var->isquote = 0;
		if (c == '\"' && var->isdouble)
		{
			var->isquote = 0;
			var->isdouble = 0;
		}
	}
	else
	{
		var->isquote = 1;
		if (c == '\"')
			var->isdouble = 1;
	}
	str_push(&var->str, c);
}

void	split_pipe_sub2(t_c *var, char c)
{
	if (c == '|' && !var->isquote)
	{
		pvec_push(&var->split, var->str.s);
		var->str = make_str();
	}
	else
		str_push(&var->str, c);
}

char	**split_pipe(const char *line)
{
	char	c;
	t_c		var;

	var = make_cmd_var();
	while (*line)
	{
		c = *line++;
		if (c == '\'' || c == '\"')
			split_pipe_sub1(&var, c);
		else
			split_pipe_sub2(&var, c);
		if (!*line)
		{
			if (*var.str.s && !var.isquote)
				pvec_push(&var.split, var.str.s);
			else
			{
				free(var.str.s);
				free_split(var.split.p);
				return (NULL);
			}
		}
	}
	return (var.split.p);
}

void	change_env_str(t_str *str, char **envp, t_str ret_str, t_str name_str)
{
	int		i;
	char	*env;

	i = -1;
	while (str->s[++i])
	{
		if (str->s[i] == '$')
		{
			while (!(str->s[i + 1] == '\'' || !str->s[i + 1] || str->s[i + 1]
					== ' ' || (str->s[i + 1] >= '\t' && str->s[i + 1] <= '\r')))
				str_push(&name_str, str->s[++i]);
			env = my_getenv(envp, name_str.s);
			free(name_str.s);
			name_str = make_str();
			while (env && *env)
				str_push(&ret_str, *env++);
		}
		else
			str_push(&ret_str, str->s[i]);
	}
	free(name_str.s);
	free(str->s);
	*str = ret_str;
}

void	pipe_cmd(char *line, char ***my_envp)
{
	char	**cmd_lines;
	pid_t	pid;
	int		status;

	pid = -10;
	cmd_lines = split_pipe(line);
	if (!cmd_lines)
		return (ft_putstr_fd("gsh: failed..pipe...\n", STDERR_FILENO));
	signal(SIGINT, SIG_IGN);
	run_pipe(0, cmd_lines, &pid, my_envp);
	status = wait_all(pid);
	signal(SIGINT, sigint_handler);
	if (pid == -10)
		return (free_split(cmd_lines));
	if (WIFEXITED(status))
		exit_code(WEXITSTATUS(status), 1);
	else if (WIFSIGNALED(status))
	{
		exit_code(WTERMSIG(status) + 128, 1);
		printf("\n");
	}
	free_split(cmd_lines);
}
