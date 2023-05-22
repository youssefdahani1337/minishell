/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:30 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/22 01:13:01 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	int		j;

	j = 0;
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = -1 * (str[i ++] - 44);
	while (ft_isdigit(str[i]))
	{
		if (j == 19 || result > 922337203685477580)
			return (-1);
		else if (result == 922337203685477580)
		{
			if (sign == 1 && str[i] > 7)
				return (-1);
			else if (sign == -1 && str[i] > 8)
				return (-1);
		}
		result = (result * 10) + (str[i ++] - 48);
		j++;
	}
	return ((result * sign) % 256);
}
