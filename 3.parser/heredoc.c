/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:34:27 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/10 11:49:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/parser.h"

void hand(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(1);
}
void	open_heredoc(t_parser *parser, int *status)
{
	while (*status == 0 && parser->type != p_terminator)
	{
		if (parser->type == limiter)
			execute_heredoc(parser, status);
		parser = parser->next;
	}
}

void	execute_heredoc(t_parser *parser, int *status)
 {
	char	*line;
	int		fd[2];
	
	signal(SIGINT, SIG_IGN);
	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]);
		signal(SIGINT, hand);
		while (1)
		{
			line = readline(HERE_DOC);
			if (!line || ft_strcmp(line, parser->value) == 0)
				break;
			write_in_her(line, fd[1], parser->state);
		}
		free(line);
		free(parser->value);
		parser->value = ft_itoa(fd[1]);
		exit(0);
	}
	else 
	{
		wait(status);
		*status = WEXITSTATUS(*status);
		g_shell.exitsts = *status;
	}
}

void	write_in_her(char *line, int fd, int state)
{
	if (!state)
		line = ft_exp(line, NULL);
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
	free(line);
}
 