/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:13:04 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/12 10:44:11 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

int	print_error(char *msg, char *special)
{
	ft_printf("\033[0;31m");
	ft_putstr_fd(msg, 2);
	if (special)
		ft_putstr_fd(special, 2);
	ft_printf("\033[0m\n");
	g_shell.exitsts = 258;
	return (0);
}
