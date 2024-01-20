/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:48:42 by inseok            #+#    #+#             */
/*   Updated: 2023/10/03 08:52:44 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig)
{
	static char	tmp;
	static int	bit;

	if (sig == SIGUSR1)
		tmp |= 0;
	else if (sig == SIGUSR2)
		tmp |= 1;
	if (bit < 7)
		tmp <<= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", tmp);
		bit = 0;
		tmp = 0;
	}
}

int	main(void)
{
	ft_printf("Server's PID : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
