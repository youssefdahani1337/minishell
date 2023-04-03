/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:13:04 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/31 16:00:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

int	print_error(char *msg, char *speciel)
{
	ft_printf("\033[0;31m");
	ft_printf("%s", msg);
	if (speciel)
		ft_printf(" '%s'", speciel);
	ft_printf("\033[0m\n");
	return (0);
}