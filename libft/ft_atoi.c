/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:10:39 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/25 01:30:27 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static	void	init(int *i, int *j, int *sign, long *result)
{
	*i = 0;
	*j = 0;
	*sign = 1;
	*result = 0;
}

static	int	return_value(int sign, long result)
{
	if (sign == -1)
		return (256 + ((result * sign) % 256));
	else
		return ((result * sign) % 256);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		sign;
	long	result;

	init(&i, &j, &sign, &result);
	while (check_white(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = -1 * (str[i ++] - 44);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || (j == 19 || result > 922337203685477580))
			return (-1);
		else if (result == 922337203685477580)
		{
			if ((sign == 1 && str[i] > '7') || (sign == -1 && str[i] > '8'))
				return (-1);
		}
		result = (result * 10) + (str[i ++] - 48);
		j++;
	}
	return (return_value(sign, result));
}
