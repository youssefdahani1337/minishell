/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:13:04 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/22 11:50:26 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

int	print_error(char *msg, char *special)
{
	ft_putstr_fd(msg, 2);
	if (special)
	{	
		ft_putchar_fd('`', 2);
		ft_putstr_fd(special, 2);
		ft_putchar_fd('\'', 2);
	}
	ft_putchar_fd('\n', 2);
	g_shell.exitsts = 258;
	return (0);
}
