/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:01:12 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/05 11:17:58 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include<stdio.h>

void	ft_putstr(const char *s, int *len);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len, char c);
void	ft_putunbr(unsigned int n, int *len);
void	ft_putbase(unsigned long long n, char c, int *len);
int		ft_printf(const char *str, ...);
#endif 
