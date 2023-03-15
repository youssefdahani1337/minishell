/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:00:06 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/10 06:32:58 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char c, va_list t, int *len)
{
	if (*(len) == -1)
		return ;
	else if (c == '%')
		ft_putchar(c, len);
	else if (c == 'c')
		ft_putchar(va_arg(t, int), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(t, int), len, 0);
	else if (c == 's')
		ft_putstr(va_arg(t, char *), len);
	else if (c == 'u')
		ft_putunbr(va_arg(t, unsigned long), len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_putbase(va_arg(t, unsigned long), 'x', len);
	}
	else if (c == 'x' || c == 'X')
		ft_putbase(va_arg(t, unsigned int), c, len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	t;
	int		i;
	int		len;
	int		check;

	check = 0;
	len = 0;
	i = 0;
	va_start(t, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			ft_check(str[++i], t, &len);
		else if (str[i])
			ft_putchar(str[i], &len);
		if (len == -1)
			return (len);
		i ++;
	}
	va_end(t);
	return (len);
}
