/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:00 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/21 22:21:52 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;

	ft_intialize_shell(env, ac, av);
	remove_ctrl_c();
	while (1337)
	{
		signal(SIGINT, handler);
		line = readline(MINISHELL_PROMPT);
		if (!line)
			break ;
		if (!*line)
		{
			free(line);
			continue ;
		}
		add_history(line);
		ft_minishell(line);
	}
	printf("exit\n");
	return (g_shell.exitsts);
}
