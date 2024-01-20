/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:57:08 by inseok            #+#    #+#             */
/*   Updated: 2023/01/23 10:57:20 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexaddress(unsigned long long address)
{
	char				*hex;
	char				mem[16];
	unsigned long long	temp;
	int					i;
	int					j;

	j = 0;
	while (j < 16)
	{
		mem[j] = '0';
		j++;
	}
	i = 0;
	hex = "0123456789abcdef";
	while (address != 0)
	{
		temp = address % 16;
		address = address / 16;
		mem[15 - i] = *(hex + temp);
		i++;
	}
	write(1, mem, 16);
	write(1, ": ", 2);
}

void	charprint(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, hex + c / 16, 1);
	write(1, hex + c % 16, 1);
}

void	ft_putstr_non_printable(unsigned char *str, int size, int line)
{
	int		i;
	int		j;

	size = size - (16 * (line));
	if (size > 16)
		j = 0;
	else
		j = 1;
	i = 0;
	while (i < 16 && j == 0)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	while (i < size && j == 1)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	hexcharprint(int i, int size, unsigned char *address2 )
{
	int	k;

	k = -1;
	while (++k < 16)
	{
		if ((i == size / 16 && k < size % 16) || i < size / 16)
		{
			charprint(address2[k]);
		}
		else
			write(1, "  ", 2);
		if (k % 2 == 1)
			write(1, " ", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned long long	address;
	unsigned char		*address2;

	i = 0;
	if (size == 0)
		return (addr);
	address2 = (unsigned char *)addr;
	while (i <= size / 16 && !(i == size / 16 && size % 16 == 0))
	{
		address = (unsigned long long)addr;
		hexaddress(address);
		hexcharprint(i, size, address2);
		ft_putstr_non_printable(address2, size, i);
		write(1, "\n", 1);
		addr = addr + 16;
		address2 = address2 + 16;
		i++;
	}	
	return (addr);
}
