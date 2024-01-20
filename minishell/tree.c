/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:00:00 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 08:53:00 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*find_node_del(t_tree *node)
{
	t_tree	*temp;

	temp = node;
	while (temp->left != NULL)
		temp = temp->left;
	return (temp);
}

t_tree	*del_node(t_tree *root, char *key)
{
	int		cmp;
	t_tree	*temp;

	temp = NULL;
	cmp = ft_strncmp(key, root->key, ft_strlen(key) + 1);
	if (cmp < 0)
		root->left = del_node(root->left, key);
	else if (cmp > 0)
		root->right = del_node(root->right, key);
	else if (cmp == 0)
	{
		if (root->left == NULL)
			return (free_tree(root, 1));
		else if (root->right == NULL)
			return (free_tree(root, 0));
		temp = find_node_del(root->right);
		ft_strlcpy(root->key, temp->key, ft_strlen(root->key) + 1);
		ft_strlcpy(root->value, temp->key, ft_strlen(root->value) + 1);
		root->right = del_node(root->right, temp->key);
	}
	return (root);
}

t_tree	*free_tree(t_tree	*root, int flag)
{
	t_tree	*temp;

	temp = NULL;
	if (flag == 1)
	{
		temp = root->right;
		free(root->key);
		free(root->value);
		free(root);
	}
	else
	{
		temp = root->left;
		free(root->key);
		free(root->value);
		free(root);
	}
	return (temp);
}

t_tree	*insert_node(t_tree	*root, char *key, char	*value)
{
	t_tree	*new_node;
	int		cmp;

	new_node = NULL;
	if (root == NULL)
	{
		new_node = (t_tree *)malloc(sizeof(t_tree));
		if (!new_node)
			exit(EXIT_FAILURE);
		new_node->key = key;
		new_node->value = value;
		new_node->left = NULL;
		new_node->right = NULL;
		return (new_node);
	}
	cmp = ft_strncmp(key, root->key, ft_strlen(key) + 1);
	if (cmp < 0)
		root->left = insert_node(root->left, key, value);
	else if (cmp > 0)
		root->right = insert_node(root->right, key, value);
	return (root);
}

void	print_tree(t_tree *root)
{
	if (root == NULL)
	{
		return ;
	}
	print_tree(root->left);
	if (root->value)
		printf("declare -x %s=\"%s\"\n", root->key, root->value);
	else
		printf("declare -x %s\n", root->key);
	print_tree(root->right);
}
