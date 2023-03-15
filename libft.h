/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:58:03 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 15:47:01 by inseok           ###   ########.fr       */
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
size_t	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int	ft_strncmp(char	*s1, char	*s2, unsigned int n);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char	*str, int c);
int	ft_atoi(char *str);
void	*ft_memchr(const void *src, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif