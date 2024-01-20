/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:45:10 by inseok            #+#    #+#             */
/*   Updated: 2023/11/04 18:25:36 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **cmds)
{
	int	i;
	int	j;

	j = 0;
	if (cmds[1])
	{
		i = 0;
		j = !ft_strncmp(cmds[1], "-n", 3);
		while (cmds[++i + j])
		{
			printf("%s", cmds[i + j]);
			if (cmds[i + j + 1])
				printf(" ");
		}
	}
	if (!j)
		printf("\n");
	exit_code(0, 1);
}
