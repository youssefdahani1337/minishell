/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intialiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:20:52 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 18:43:33 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_intialize_shell(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	g_shell.exitsts = 0;
	g_shell.env = ft_env_fill(env);
	if (!g_shell.env)
	{
		g_shell.exitsts = 1;
		return (0);
	}
	g_shell.unsetpwd = 0;
	g_shell.opwd = 0;
	g_shell.table = NULL;
	return (1);
}
