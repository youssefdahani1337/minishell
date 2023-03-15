/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:19:39 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/05 09:30:42 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(unsigned long long num, char c, int *len)
{
	char	*str;

	if ((*len) == -1)
		return ;
	if (c == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if ((num / 16) > 0)
	{
		ft_putbase(num / 16, c, len);
		ft_putchar(str[num % 16], len);
	}
	else
		ft_putchar(str[num % 16], len);
}
