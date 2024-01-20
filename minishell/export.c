/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:42:36 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 18:33:17 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_my_envp(char **cmds, char ***my_envp)
{
	t_pvec		new_envp;
	t_str		env_str;
	int			i;
	int			j;

	i = 0;
	new_envp = make_pvec();
	while ((*my_envp)[i + 1])
	{
		pvec_push(&new_envp, (*my_envp)[i]);
		i++;
	}
	env_str = make_str();
	j = -1;
	while (cmds[1][++j])
		str_push(&env_str, cmds[1][j]);
	pvec_push(&new_envp, env_str.s);
	pvec_push(&new_envp, (*my_envp)[i]);
	free(*my_envp);
	*my_envp = new_envp.p;
}

t_tree	*make_export_envp(char ***my_envp)
{
	t_tree		*export_envp;
	t_str		env_str;
	t_str		env_str2;
	int			i;
	int			j;

	export_envp = NULL;
	i = 0;
	while ((*my_envp)[i])
	{
		j = -1;
		env_str = make_str();
		env_str2 = make_str();
		while ((*my_envp)[i][++j] && (*my_envp)[i][j] != '=')
			str_push(&env_str, (*my_envp)[i][j]);
		while ((*my_envp)[i][++j])
			str_push(&env_str2, (*my_envp)[i][j]);
		export_envp = insert_node(export_envp, env_str.s, env_str2.s);
		i++;
	}
	return (export_envp);
}

void	builtin_export(char **cmds, char ***my_envp, int flag)
{
	static t_tree	*root;

	if (flag == 1)
		root = make_export_envp(my_envp);
	else if (flag == 0)
	{
		if (cmds[1])
		{
			if (!isvalid_export(cmds))
			{
				ft_putstr_fd(sum_msg("gsh: export: `", cmds[1], 0), 2);
				ft_putstr_fd("\': not a valid identifier\n", 2);
				exit_code(1, 1);
				return ;
			}
			if (find_cmds_my_envp(cmds, my_envp))
				add_my_envp(cmds, my_envp);
			find_key(root, cmds);
		}
		else
			print_tree(root);
	}
	else if (flag == 2)
		del_export(cmds, root);
	exit_code(0, 1);
}

void	del_export(char **cmds, t_tree *root)
{
	t_str			env_str;
	int				j;

	j = -1;
	env_str = make_str();
	while (cmds[1][++j] && cmds[1][j] != '=')
		str_push(&env_str, cmds[1][j]);
	if (is_del(root, env_str.s))
		root = del_node(root, env_str.s);
	free(env_str.s);
}
