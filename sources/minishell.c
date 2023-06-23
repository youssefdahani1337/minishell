/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:00 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/23 03:34:58 by yodahani         ###   ########.fr       */
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
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		line = readline(MINISHELL_PROMPT);
		signal(SIGINT, SIG_IGN);
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
