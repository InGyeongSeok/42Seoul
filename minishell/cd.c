/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:32:12 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 18:27:53 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_sub_save(char ***my_envp)
{
	char	*ptr;
	t_pvec	pvec;

	ptr = my_getenv(*my_envp, "PWD");
	if (ptr)
	{
		pvec = make_pvec();
		pvec_push(&pvec, make_str().s);
		pvec_push(&pvec, ft_strdup(sum_msg("OLDPWD=", ptr, 0)));
		builtin_export(pvec.p, my_envp, 0);
		free_split(pvec.p);
	}
}

static void	cd_sub(const char *dest, char *olddest, char ***my_envp)
{
	t_pvec	pvec;
	char	buf[1024];

	if (olddest)
		dest = olddest;
	if (chdir(dest) < 0)
		perror(sum_msg("gsh: cd: ", dest, 0));
	else
	{
		cd_sub_save(my_envp);
		if (getcwd(buf, 1024))
		{
			pvec = make_pvec();
			pvec_push(&pvec, make_str().s);
			pvec_push(&pvec, ft_strdup(sum_msg("PWD=", buf, 0)));
			builtin_export(pvec.p, my_envp, 0);
			free_split(pvec.p);
		}
		if (olddest)
			builtin_pwd(NULL, my_envp);
	}
	free(olddest);
}

void	builtin_cd(char **cmds, char ***my_envp)
{
	const char	*dest = cmds[1];
	char		*olddest;

	olddest = NULL;
	if (!dest || 0 == ft_strncmp(dest, "~", 2))
	{
		dest = my_getenv(*my_envp, "HOME");
		if (!dest)
		{
			ft_putstr_fd("gsh: cd: HOME not set\n", STDERR_FILENO);
			return ((void)exit_code(1, 1));
		}
	}
	else if (0 == ft_strncmp(dest, "-", 2))
	{
		dest = my_getenv(*my_envp, "OLDPWD");
		if (!dest)
		{
			ft_putstr_fd("gsh: cd: OLDPWD not set\n", STDERR_FILENO);
			return ((void)exit_code(1, 1));
		}
		olddest = ft_strdup(dest);
	}
	cd_sub(dest, olddest, my_envp);
	exit_code(0, 1);
}
