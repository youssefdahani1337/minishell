/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:17:00 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 11:58:04 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_readline(int check)
{
	char	*line;

	if (check)
			line = readline(MINISHELL_PROMPT);
	else
		line = readline(MINISHELL_PROMPT_ERROR);
	return (line);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	int		check;

	check = 1;
	ft_intialize_shell(env, ac, av);
	while (1337)
	{
		line = ft_readline(check);
		if (!line)
			break ;
		if (!*line)
		{
			free(line);
			continue ;
		}
		add_history(line);
		check = ft_minishell(line);
	}
	return (0);
}
