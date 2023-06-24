/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:34:27 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/24 22:09:45 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	open_heredoc(t_parser *parser, int *status)
{
	int	status2;

	status2 = 0;
	count_herdoc(parser, status);
	while (status2 == 0 && parser->type != p_terminator)
	{
		if (parser->type == limiter)
			execute_heredoc(parser, &status2);
		parser = parser->next;
	}
	if (status2)
		*status = status2;
}

void	execute_heredoc(t_parser *parser, int *status)
{	
	int		fd[2];
	pid_t	id;

	pipe(fd);
	id = fork();
	if (id == 0)
		herdoc_iter(parser, fd);
	else if (id == -1)
	{
		perror("MINISHELL:");
		*status = 1;
	}
	else
	{
		waitpid(id, status, 0);
		close(fd[1]);
		*status = WEXITSTATUS(*status);
		free(parser->value);
		parser->value = ft_itoa(fd[0]);
	}
}

void	herdoc_iter(t_parser *parser, int fd[2])
{
	char	*line;

	close(fd[0]);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, hand);
	while (1)
	{
		line = readline(HERE_DOC);
		if (!line || ft_strcmp(line, parser->value) == 0)
			break ;
		write_in_her(line, fd[1], parser->state);
		ft_putstr_fd("\n", fd[1]);
	}
	close(fd[1]);
	free(line);
	exit(0);
}

void	write_in_her(char *line, int fd, int state)
{
	if (!state)
		line = ft_exp(line);
	ft_putstr_fd(line, fd);
	free(line);
}

void	count_herdoc(t_parser *parser, int *status)
{
	int	i;

	i = 0;
	while (parser->type != p_terminator)
	{
		if (parser->type == limiter)
			i ++;
		parser = parser->next;
	}
	if (i > 16)
	{
		*status = 1;
		printf("maximum here-document count exceeded\n");
		exit(2);
	}
}
