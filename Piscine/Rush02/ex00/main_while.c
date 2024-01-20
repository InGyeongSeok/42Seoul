/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunlee <gunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:15:54 by gunlee            #+#    #+#             */
/*   Updated: 2023/01/29 22:20:48 by gunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
void	ft_putdict_mod(char *str, int mod_str, char **dict_arr);
void	ft_test(int moc_str, char **dict_arr);
void	ft_putdict_idx0(char c, char **dict_arr);
void	ft_putdict_idx1_teen(char c, char idx3_val, char **dict_arr);
void	ft_putdict_idx1_ty(char c, char **dict_arr);
void	ft_putdict(char c, char **dict_arr);

int	if_loop_until3_1(char *str, char **dict_arr, int loop_until3, int i)
{
	if (str[i + 1] == '1')
	{
		ft_putdict_idx1_teen(str[i + 1], str[i + 1 + 1], dict_arr);
		loop_until3 += 2;
	}
	else if (str[i + 1] != '0')
	{
		ft_putdict_idx1_ty(str[i + 1], dict_arr);
		loop_until3++;
	}
	else
		loop_until3++;
	return (loop_until3);
}

int	loop_while_3box(char *str, char **dict_arr, int loop_until3, int i)
{
	while (3 > loop_until3)
	{
		if (loop_until3 == 0 && str[i] != '0')
		{
			ft_putdict_idx0(str[i], dict_arr);
			loop_until3++;
		}
		else if (loop_until3 == 1)
		{
			loop_until3 = if_loop_until3_1(str, dict_arr, loop_until3, i);
		}
		else if (loop_until3 == 2 && str[i + 2] != '0')
		{
			ft_putdict(str[i + 2], dict_arr);
			loop_until3++;
		}
		else
			loop_until3++;
	}
	return (loop_until3);
}

void	main_while(char **dict_arr, char *str, int i, int len_argv)
{
	int	mod_str;
	int	moc_str;
	int	flag;
	int	loop_until3;

	moc_str = len_argv / 3;
	mod_str = len_argv % 3;
	flag = mod_str;
	ft_putdict_mod(str, mod_str, dict_arr);
	i += mod_str;
	while (moc_str)
	{	
		if (flag != 0)
			ft_test(moc_str, dict_arr);
		flag = 1;
		loop_until3 = 0;
		loop_until3 = loop_while_3box(str, dict_arr, loop_until3, i);
		i += 3;
		moc_str--;
	}
}
