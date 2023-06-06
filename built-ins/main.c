/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:47:23 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/06 15:30:39 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	main(int argc, char **argv, char **env)
{
	t_cmdtable	cmd;

	(void)argc;
	cmd.cmd = argv + 1;
	g_shell.env = ft_env_fill(env);
	g_shell.fst_time = 0;
	ft_unset(&cmd);
	return (0);
}