/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:19:11 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/04 16:43:37 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_msgexitsts(char *str, int errnum)
{
	g_shell.exitsts = errnum;
	perror(str);
}

int	ft_intialize_shell(char **av, char **env)
{
	(void)av;
	g_shell.env = ft_env_fill(env);
	g_shell.exitsts = 0;
	g_shell.table = malloc(sizeof(t_cmdtable));
	if (!(g_shell.table))
	{
		ft_msgexitsts("allocation", errno);
		return (0);
	}
	g_shell.table->outfile = malloc(sizeof(t_file));
	if (!(g_shell.table->outfile))
	{
		ft_msgexitsts("allocation", errno);
		return (0);
	}
	g_shell.table->cmd = av;
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	//t_env	*p;

	(void)argc;
	if (ft_intialize_shell(argv + 1, env) == 1)
	{
		// p = g_shell.env;
		// while (p)
		// {
		// 	printf("[%s]\n", p->key);
		// 	p = p->next;
		// }
		// t_env	*p;
		// p = g_shell.env;
		// while (p)
		// {
		// 	printf("[%s]\n", p->key);
		// 	p = p->next;
		// }
		// ft_export();
		ft_env();
	}
	return (0);
}
