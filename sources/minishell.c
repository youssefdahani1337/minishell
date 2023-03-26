/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:00 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 15:00:39 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_shell	*shell;

	if (ac < 0 || !av || !env)
		return (0);
	ft_intialize_shell(&shell, env);
	while (1337)
	{
		line = readline(MINISHELL_PROMPT);
		//if (!line || !line[0])
		//	return (0);		
		add_history(line);
		printf("command :%s\n", line);
		ft_minishell(line);
		free(line);
	}
	return (0);
}
