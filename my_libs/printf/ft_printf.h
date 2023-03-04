/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:34:06 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/15 15:40:13 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

void				ft_putchar(const char c, int *counter);
void				ft_putstr(const char *s, int *counter);
void				ft_putnbr(int nb, int *counter);
int					ft_printf(const char *s, ...);
void				ft_puthex(unsigned int n, int isupper, int *counter);
void				ft_puthex_long(unsigned long n, int isupper, int *counter);
void				ft_putunbr(unsigned int n, int *counter);
#endif
