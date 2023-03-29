/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:19:11 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/29 16:42:17 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_intialize_shell(char **av, char **env)
{
	g_shell.env = ft_env(env);
	g_shell.exitsts = 0;
	g_shell.table->cmd = av;
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	ft_intialize_shell(argv + 1, env);
}
