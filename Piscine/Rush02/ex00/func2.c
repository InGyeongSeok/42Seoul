/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunlee <gunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:23:37 by gunlee            #+#    #+#             */
/*   Updated: 2023/01/29 21:46:53 by gunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmpteen(char c1, char c2, char *s);
void	arr_write(char *arr);
int		ft_strcmpty(char c1, char *s);
int		ft_strcmpone(char c, char *dict);
int		ft_strcmp_hund(char *hund, char *s);
int		ft_is_space_colon(char c);
void	ft_putdict_idx0_2(char c, char **dict_arr);

void	ft_putdict_idx1_teen(char c, char idx3_val, char **dict_arr )
{
	int	i;

	i = 0;
	while (*dict_arr)
	{
		if (ft_strcmpteen(c, idx3_val, *dict_arr) == 1)
		{
			arr_write(*dict_arr);
			break ;
		}
		dict_arr++;
		i++;
	}
	dict_arr -= i;
	return ;
}

void	ft_putdict_idx1_ty(char c, char **dict_arr)
{
	int	i;

	i = 0;
	while (*dict_arr)
	{
		if (ft_strcmpty(c, *dict_arr) == 1)
		{
			arr_write(*dict_arr);
			break ;
		}
		dict_arr++;
		i++;
	}
	dict_arr -= i;
	return ;
}

void	ft_putdict_idx0(char c, char **dict_arr)
{
	int		i;

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
	ft_putdict_idx0_2(c, dict_arr);
}

void	ft_putdict_idx0_2(char c, char **dict_arr)
{
	int		i;
	char	*hund;

	(void)c;
	i = 0;
	hund = "100";
	while (*dict_arr)
	{
		if (ft_strcmp_hund(hund, *dict_arr) == 1)
		{
			arr_write(*dict_arr);
			break ;
		}
		dict_arr++;
		i++;
	}
	dict_arr -= i;
	return ;
}

int	ft_strcmpover(int i, char *dict)
{
	if (dict[i] == '0' && ft_is_space_colon(dict[i + 1]))
		return (1);
	return (-1);
}
