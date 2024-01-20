/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:42:35 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 19:52:44 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isvalid_export(char **cmds)
{
	int		i;

	if (!((cmds[1][0] >= 'a' && cmds[1][0] <= 'z')
		|| (cmds[1][0] >= 'A' && cmds[1][0] <= 'Z')) && !(cmds[1][0] == '_'))
		return (0);
	i = 1;
	while (cmds[1][i] && cmds[1][i] != '=')
	{
		if (!((cmds[1][i] >= 'a' && cmds[1][i] <= 'z')
			|| (cmds[1][i] >= 'A' && cmds[1][i] <= 'Z')) &&
			!(cmds[1][i] <= '0' && cmds[1][i] >= '9') && !(cmds[1][i] == '_'))
			return (0);
		++i;
	}
	return (1);
}

int	find_cmds_my_envp(char **cmds, char ***my_envp)
{
	int			count;
	t_str		env_str;
	int			i;
	int			j;

	count = find_equal(cmds);
	if (count < 1)
		return (0);
	i = -1;
	j = -1;
	while ((*my_envp)[++i])
	{
		if (!ft_strncmp(cmds[1], (*my_envp)[i], count + 1))
		{
			env_str = make_str();
			while (cmds[1][++j])
				str_push(&env_str, cmds[1][j]);
			free((*my_envp)[i]);
			(*my_envp)[i] = env_str.s;
			return (0);
		}
	}
	return (1);
}

int	find_equal(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1][i])
	{
		if (cmd[1][i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	search(t_tree *root, char *key, char *value)
{
	int	cmp;

	if (root == NULL)
		return (0);
	cmp = ft_strncmp(key, root->key, ft_strlen(key) + 1);
	if (cmp == 0)
	{
		free(root->key);
		root->key = key;
		if (!value && root->value)
			return (1);
		free(root->value);
		root->value = value;
		return (1);
	}
	else if (cmp < 0)
		return (search(root->left, key, value));
	return (search(root->right, key, value));
}

void	find_key(t_tree *root, char **cmds)
{
	t_str	env_str;
	t_str	env_str2;
	int		j;

	j = -1;
	env_str = make_str();
	env_str2 = make_str();
	while ((cmds)[1][++j] && (cmds)[1][j] != '=')
		str_push(&env_str, (cmds)[1][j]);
	if (cmds[1][j])
	{
		while ((cmds)[1][++j])
			str_push(&env_str2, (cmds)[1][j]);
	}
	else
	{
		free(env_str2.s);
		env_str2.s = NULL;
	}
	if (search(root, env_str.s, env_str2.s))
		return ;
	root = insert_node(root, env_str.s, env_str2.s);
	return ;
}
