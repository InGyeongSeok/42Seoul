/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:08:44 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 18:34:01 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_my_envp(char **cmds, char ***my_envp)
{
	t_pvec	new_envp;
	int		i;

	i = -1;
	new_envp = make_pvec();
	while ((*my_envp)[++i])
	{
		if (!ft_strncmp(sum_msg(cmds[1], "=", 0), (*my_envp)[i],
			ft_strlen(cmds[1]) + 1))
			free((*my_envp)[i]);
		else
			pvec_push(&new_envp, (*my_envp)[i]);
	}
	free(*my_envp);
	*my_envp = new_envp.p;
}

void	builtin_unset(char **cmds, char ***my_envp)
{
	if (cmds[1])
	{
		if (!isvalid_export(cmds))
		{
			ft_putstr_fd(sum_msg("gsh: unset: `", cmds[1], 0), 2);
			ft_putstr_fd("\': not a valid identifier\n", 2);
			exit_code(1, 1);
			return ;
		}
		del_my_envp(cmds, my_envp);
		builtin_export(cmds, my_envp, 2);
	}
	exit_code(0, 1);
}

int	is_del(t_tree *root, char *key)
{
	int	cmp;

	if (root == NULL)
		return (0);
	cmp = ft_strncmp(key, root->key, ft_strlen(root->key) + 1);
	if (cmp == 0)
		return (1);
	else if (cmp < 0)
		return (is_del(root->left, key));
	return (is_del(root->right, key));
}
