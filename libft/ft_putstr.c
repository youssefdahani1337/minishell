/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:00:21 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/03 07:01:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *str, int *len)
{
	if ((*len) == -1)
		return ;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*str && *len != -1)
		ft_putchar(*(str ++), len);
}

void	ft_putchar(char c, int *len)
{
	if (*len == -1 || write(1, &c, 1) == -1)
	{
		(*len) = -1;
		return ;
	}
	(*len)++;
}
