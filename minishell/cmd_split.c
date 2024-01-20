/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:17:37 by seonglim          #+#    #+#             */
/*   Updated: 2023/10/29 06:51:04 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_c	make_cmd_var(void)
{
	t_c	var;

	var.split = make_pvec();
	var.str = make_str();
	var.isquote = 0;
	var.isdouble = 0;
	var.i = 0;
	return (var);
}

static void	cmd_split_sub1(char *line, char **envp, t_c *var)
{
	if (var->isquote)
	{
		if ((line[var->i] == '\'' && !var->isdouble)
			|| (line[var->i] == '\"' && var->isdouble))
		{
			if (line[var->i + 1] == '\0' || line[var->i + 1] == ' ')
			{
				if (var->isdouble)
					change_env_str(&var->str, envp, make_str(), make_str());
				pvec_push(&var->split, var->str.s);
				var->str = make_str();
			}
			var->isquote = 0;
			var->isdouble = 0;
		}
		else
			str_push(&var->str, line[var->i]);
	}
	else
	{
		var->isquote = 1;
		if (line[var->i] == '\"')
			var->isdouble = 1;
		change_env_str(&var->str, envp, make_str(), make_str());
	}
}

static void	cmd_split_sub2(char *line, char **envp, t_c *var)
{
	if (var->isquote)
		str_push(&var->str, line[var->i]);
	else
	{
		if (line[var->i] != ' ')
			str_push(&var->str, line[var->i]);
		else if (var->str.size != 0)
		{
			change_env_str(&var->str, envp, make_str(), make_str());
			pvec_push(&var->split, var->str.s);
			var->str = make_str();
		}
	}
}

static void	cmd_split_sub3(char **envp, t_c *var, int flag)
{
	if (flag)
	{
		ft_putstr_fd("gsh: quote failed..\n", 2);
		free(var->str.s);
		free_split(var->split.p);
	}
	else
	{
		change_env_str(&var->str, envp, make_str(), make_str());
		pvec_push(&var->split, var->str.s);
	}
}

char	**cmd_split(char *line, char **envp)
{
	t_c	var;

	var = make_cmd_var();
	while (1)
	{
		if (line[var.i] == '\'' || line[var.i] == '\"')
			cmd_split_sub1(line, envp, &var);
		else
			cmd_split_sub2(line, envp, &var);
		if (!line[++var.i])
		{
			if (var.isquote)
			{
				cmd_split_sub3(envp, &var, 1);
				return ((char **)(size_t) !exit_code(258, 1));
			}
			else if (var.str.size != 0)
				cmd_split_sub3(envp, &var, 0);
			else
				free(var.str.s);
			break ;
		}
	}
	return (var.split.p);
}
