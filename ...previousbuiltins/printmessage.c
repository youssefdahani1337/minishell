/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmessage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:25:27 by hbenabad          #+#    #+#             */
/*   Updated: 2023/05/26 10:56:59 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_msgexitsts(char *str, int status)
{
	g_shell.exitsts = status;
	ft_putstr_fd("minishell: ", 1);
	ft_putstr_fd(str, 1);
}
