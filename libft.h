/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:58:03 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 10:50:52 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

////////////////테스트를 위한 것
# include <stdio.h>
# include <string.h>
# include <ctype.h>
////////////////////

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_strlen(char *str);
void	*ft_memset(void *ptr, int value, int num);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void	*dest, const void	*source, int num);
void	*ft_memmove(void *dest, const void *src, int num);
#endif