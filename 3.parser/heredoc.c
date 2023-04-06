/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:34:27 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/05 02:17:29 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/parser.h"

int			open_heredoc(t_parser *parser)
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
	int		pid;
	char	*line;

	int	fd = open("filename", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
;
	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			line = readline("__Here doc__");
			if (ft_strcmp(line, parser->value) == 0)
				break;
			ft_putstr_fd(line, fd);	
			ft_putstr_fd("\n", fd);	
			free(line);
		}
		close(fd);
	}
	else
		wait(NULL);
 }
 
 