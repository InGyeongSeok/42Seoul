/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:50:23 by inseok            #+#    #+#             */
/*   Updated: 2023/10/03 08:56:11 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_strjoinendl(const char *s1, const char *s2)
{
	size_t	index;
	size_t	len;
	char	*result;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	index = 0;
	while (*s1 != '\0')
		result[index++] = *s1++;
	while (*s2 != '\0')
		result[index++] = *s2++;
	result[index] = '\0';
	return (result);
}

void	send_msg(int pid, char*str)
{
	int	index;
	int	bit;
	int	tmp;

	index = -1;
	while (++index < (int) ft_strlen(str))
	{
		bit = -1;
		while (++bit < 8)
		{
			tmp = str[index] >> (7 - bit) & 1;
			if (tmp == 0)
				kill(pid, SIGUSR1);
			else if (tmp == 1)
				kill(pid, SIGUSR2);
			usleep(30);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Wrong arguments\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	message = ft_strjoinendl(argv[2], "\n");
	if (!message)
		exit(1);
	send_msg(pid, message);
	free(message);
	return (0);
}
