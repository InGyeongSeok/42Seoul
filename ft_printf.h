/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:06:14 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 17:08:18 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //가변인자
# include <unistd.h> //write
# include <stdlib.h> //동적할당

int	handleSpecifier(const char format, va_list* ap);
int	ft_printf(const char *format, ...);


int	printf_c(va_list *ap);
int	printf_s(va_list *ap);
int	printf_p(va_list *ap);
int	printf_d(va_list *ap);
int	printf_u(va_list *ap);
int	printf_x(va_list *ap, const char format);



size_t	ft_strlen(const char *str);
char *printf_itoa(long n);


#endif