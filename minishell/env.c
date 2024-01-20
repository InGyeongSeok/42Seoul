/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:47:41 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 18:34:16 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(char **cmds, char ***my_envp)
{
	int	i;

	i = 0;
	while ((*my_envp)[i])
	{
		printf("%s\n", (*my_envp)[i]);
		i++;
	}
	exit_code(0, 1);
	(void)cmds;
}
