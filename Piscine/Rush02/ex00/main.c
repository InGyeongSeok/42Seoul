/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwoc <seongwoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:41:27 by seongwoc          #+#    #+#             */
/*   Updated: 2023/01/29 22:42:23 by seongwoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**read_dict(char *dict_name);
void	main_while(char **dict_arr, char *str, int i, int len_argv);
int		ft_strlen(char *str);

int	max_dict_err(int input_len)
{
	if (input_len > 37)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

int	is_valid_input(int i, int count, char *str_argv)
{
	while (str_argv[i])
	{
		if (!(str_argv[i] >= '0' && str_argv[i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (str_argv[i] == '0')
			count++;
		i++;
	}
	if (count != 1 && str_argv[0] == '0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	free_2(char **dict_arr)
{
	int	cnt;

	cnt = 0;
	while (*dict_arr)
	{
		free(*dict_arr);
		dict_arr++;
		cnt++;
	}
	dict_arr -= cnt;
	free(dict_arr);
}

int	empty_err(int argc)
{
	if (argc == 1)
	{	
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**dict_arr;
	int		len_argv;
	int		i;
	int		count;

	if (empty_err(argc))
		return (0);
	if (!((argc == 2) || (argc == 3)))
		return (0);
	if (argc == 2)
		dict_arr = read_dict("numbers.dict");
	else if (argc == 3)
		dict_arr = read_dict(argv[1]);
	i = 0;
	count = 0;
	if (!(is_valid_input(i, count, argv[1])))
		return (0);
	i = 0;
	len_argv = ft_strlen(argv[1]);
	if (max_dict_err(len_argv))
		return (0);
	main_while(dict_arr, argv[1], i, len_argv);
	free_2(dict_arr);
	return (0);
}
