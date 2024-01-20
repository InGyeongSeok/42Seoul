/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunlee <gunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:26:36 by gunlee            #+#    #+#             */
/*   Updated: 2023/01/29 21:47:20 by gunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_space_colon(char c);
int		ft_strcmpover(int i, char *dict);
void	arr_write(char *arr);

int	ft_strcmpty(char c1, char *s)
{
	if (s[0] == c1 && s[1] == '0' && ft_is_space_colon(s[2]))
		return (1);
	return (-1);
}

int	ft_strcmp_hund(char *hund, char *s)
{
	if (s[0] == *hund && s[1] == '0' && s[2] == '0' && ft_is_space_colon(s[3]))
		return (1);
	return (-1);
}

void	ft_test(int moc_str, char **dict_arr)
{
	int	i;

	i = 0;
	while (*dict_arr)
	{
		if (ft_strcmpover(moc_str * 3, *dict_arr) == 1)
		{
			arr_write(*dict_arr);
			break ;
		}
		dict_arr++;
		i++;
	}
	dict_arr -= i;
}
