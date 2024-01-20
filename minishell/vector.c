/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:17:46 by seonglim          #+#    #+#             */
/*   Updated: 2023/10/22 08:19:38 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pvec	make_pvec(void)
{
	t_pvec	ret;

	ret.size = 0;
	ret.p = malloc(sizeof(char *) * 1);
	if (!ret.p)
		exit(EXIT_FAILURE);
	*ret.p = NULL;
	return (ret);
}

t_str	make_str(void)
{
	t_str	ret;

	ret.size = 0;
	ret.s = malloc(sizeof(char) * 1);
	if (!ret.s)
		exit(EXIT_FAILURE);
	*ret.s = '\0';
	return (ret);
}

void	pvec_push(t_pvec *pvec, char *str)
{
	int		i;
	char	**p;

	p = malloc(sizeof(char *) * (pvec->size + 2));
	if (!p)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < pvec->size)
	{
		p[i] = pvec->p[i];
		++i;
	}
	p[pvec->size++] = str;
	p[pvec->size] = NULL;
	free(pvec->p);
	pvec->p = p;
}

void	str_push(t_str *str, char c)
{
	int		i;
	char	*s;

	s = malloc(sizeof(char) * (str->size + 2));
	if (!s)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < str->size)
	{
		s[i] = str->s[i];
		++i;
	}
	s[str->size++] = c;
	s[str->size] = '\0';
	free(str->s);
	str->s = s;
}
