/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:00 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/02 14:35:47 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	int		check;
	
	(void)ac;
	(void)av;
	check = 1;
	ft_intialize_shell(env);
	while (1337)
	{
		if (check)
			line = readline(MINISHELL_PROMPT);
		else 
			line = readline(MINISHELL_PROMPT_ERROR);
		if (!line || !line[0])
			continue;
		add_history(line);
		printf("command :%s\n", line);
		check = ft_minishell(line);
		free(line);
	}
	return (0);
}
