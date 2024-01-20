/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunlee <gunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:25:01 by gunlee            #+#    #+#             */
/*   Updated: 2023/01/29 21:26:19 by gunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmpone(char c, char *dict);
int		ft_strcmpty(char c1, char *s);
void	ft_putdict_idx1_teen(char c, char idx3_val, char **dict_arr );
void	ft_putdict_mod2(char *str, int mod_str, char **dict_arr, int i);

void	arr_write(char *arr)
{
	int	i;

	i = 0;
	while ((arr[i] >= '0' && arr[i] <= '9'))
		i++;
	while ((arr[i] <= 13 && arr[i] >= 9) || arr[i] == 32)
		i++;
	while (arr[i] == ':')
		i++;
	while ((arr[i] <= 13 && arr[i] >= 9) || arr[i] == 32)
		i++;
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
	write(1, " ", 1);
}

void	ft_putdict(char c, char **dict_arr)
{
	int	i;

	i = 0;
	while (*dict_arr)
	{
		if (ft_strcmpone(c, *dict_arr) == 1)
		{
			arr_write(*dict_arr);
			break ;
		}
		dict_arr++;
		i++;
	}
	dict_arr -= i;
}

void	ft_putdict_mod(char *str, int mod_str, char **dict_arr)
{
	int	i;

	i = 0;
	if (mod_str == 1)
	{
		while (*dict_arr)
		{
			if (ft_strcmpone(*str, *dict_arr) == 1)
			{
				arr_write(*dict_arr);
				break ;
			}
			dict_arr++;
			i++;
		}
		dict_arr -= i;
	}
	else if (mod_str == 2 && *str == '1')
	{
		ft_putdict_idx1_teen(*str, *(str +1), dict_arr);
	}
	else if (mod_str == 2)
		ft_putdict_mod2(str, mod_str, dict_arr, i);
}

void	ft_putdict_mod2(char *str, int mod_str, char **dict_arr, int i)
{
	if (mod_str == 2)
	{	
		while (*dict_arr)
		{
			if (ft_strcmpty(*str, *dict_arr) == 1)
			{
				arr_write(*dict_arr);
				break ;
			}
			dict_arr++;
			i++;
		}
		dict_arr -= i;
		while (*dict_arr)
		{
			if (ft_strcmpone(*(str + 1), *dict_arr) == 1)
			{
				arr_write(*dict_arr);
				break ;
			}
			dict_arr++;
			i++;
		}
		dict_arr -= i;
	}
}
