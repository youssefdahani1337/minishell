/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:10:42 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 15:12:36 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

static int	check_white(char c)
{
	char	*sp;

	sp = " \t\r\n\f\v";
	while (*sp)
	{
		if (*sp == c)
			return (1);
		sp ++;
	}
	return (0);
}

int	atoi_m(const char	*str)
{
	int		i;
	int		sign;
	long	result;
	long	t;

	t = 0;
	result = 0;
	sign = 1;
	i = 0;
	while (check_white(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
			sign = -1 * (str[i ++] - 44);
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i ++] - 48);
		if (t > result)
			return (-1 * (sign > 0));
		t = result;
	}
	retur
}
