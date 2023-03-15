/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:13:41 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/05 11:03:56 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len, char c)
{
	long	num;

	if ((*len) == -1)
		return ;
	if ((c == 32 || c == 43) && n > 0)
		ft_putchar(c, len);
	num = n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-', len);
	}
	if ((num / 10) > 0)
		ft_putnbr(num / 10, len, 0);
	ft_putchar((num % 10) + 48, len);
}

void	ft_putunbr(unsigned int num, int *len)
{
	if ((*len) == -1)
		return ;
	if ((num / 10) > 0)
	{
		ft_putunbr(num / 10, len);
		ft_putchar((num % 10) + 48, len);
	}
	else
		ft_putchar((num % 10) + 48, len);
}
