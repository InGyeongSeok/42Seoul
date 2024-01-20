/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:27:01 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 18:31:00 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(char **cmds, char ***my_envp)
{
	char	*env;

	env = my_getenv(*my_envp, "PWD");
	if (env)
		printf("%s", env);
	printf("\n");
	exit_code(0, 1);
	(void)cmds;
}
