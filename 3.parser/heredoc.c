/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:34:27 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/25 16:44:19 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/parser.h"

int		open_heredoc(t_parser *parser)
{
	while (parser->type != p_terminator)
	{
		if (parser->type == limiter)
			execute_heredoc(parser);
		parser = parser->next;
	}
	return (1);
}

 void	execute_heredoc(t_parser *parser)
 {
	char	*line;
	int		fd[2];
	
	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = readline("__Here doc__");
			if (ft_strcmp(line, parser->value) == 0)
				break;
			write_in_her(line, fd[1], parser->state);
		}
		free(parser->value);
		parser->value = ft_itoa(fd[1]);
	}
	else
		wait(NULL);
}

void	write_in_her(char *line, int fd, int state)
{
	if (!state)
		line = ft_exp(line, NULL);
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
	free(line);
}
 