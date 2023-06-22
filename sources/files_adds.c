/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_adds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:28:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/21 22:22:34 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	file_addback(t_file **files, t_file *new)
{
	t_file		*tmp;

	tmp = *files;
	if (!*files)
		*files = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_file	*new_file(int fd, char *msg)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	file->fd = fd;
	file->error = msg;
	file->next = NULL;
	return (file);
}

t_file	*open_file(t_parser *parser, int *status)
{
	int		fd;
	char	*msg;

	if (parser->state == -1)
		return (new_file(-1, ft_strdup(": ambiguous redirect")));
	msg = NULL;
	if (parser->type == infile)
		fd = open(parser->value, O_RDONLY);
	else if (parser->type == outfile)
		fd = open(parser->value, O_CREAT | O_WRONLY | O_TRUNC, 0677);
	else
		fd = open(parser->value, O_CREAT | O_WRONLY | O_APPEND, 0677);
	if (fd == -1)
	{
		msg = ft_strjoin(parser->value, " : ");
		msg = ft_strjoin_m(msg, ft_strdup(strerror(errno)));
		parser->value = NULL;
		*status = -1;
	}
	return (new_file(fd, msg));
}

t_file	*addfile(t_parser *parser)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = atoi_m(parser->value);
	file->error = NULL;
	file->next = NULL;
	return (file);
}
