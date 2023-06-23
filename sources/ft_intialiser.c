/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intialiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:20:52 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 03:49:58 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_intialize_shell(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	g_shell.env_save = env;
	g_shell.env = ft_env_fill(env);
	g_shell.exitsts = 0;
	g_shell.unsetpwd = 0;
	g_shell.opwd = 0;
	g_shell.table = NULL;
}
