/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intialiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:20:52 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/25 01:10:10 by yodahani         ###   ########.fr       */
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
		return (0);
	if (!ft_getenv("PWD") && !ft_setpwd())
		return (0);
	if (!ft_shlvl())
	{
		g_shell.exitsts = 1;
		return (0);
	}
	g_shell.opwd = 0;
	g_shell.unsetpwd = 0;
	return (1);
}
