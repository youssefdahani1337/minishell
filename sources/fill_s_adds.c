/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_s_adds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:56:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/31 19:41:02 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_t_parse(t_parser *parser, int type)
{
	int	i;

	i = 0;
	while (parser->type != p_pip && parser->value != p_terminator)
	{
		if (parser->type == type)
			i ++;
		parser = parser->next;
	}
	return (i);
}

void	skip_parse(t_parser **parser)
{
	while ((*parser)->type != p_pip && (*parser)->type != p_terminator)
		(*parser) = (*parser)->next;
}

void	get_cmd(char ***cmd, t_parser *parser)
{
	int	i;

	i = 0;
	*cmd = malloc(sizeof(char *) * (count_t_parse(parser, p_string) + 1));
	while (parser->type != p_pip && parser->value != p_terminator)
	{
		if (parser->type == p_string)
			*cmd[i++] = ft_strdup(parser->value);
		parser = parser->next;
	}
}

void	get_infile(t_file *file, t_parser *parser)
{
	t_file *infile;

	infile = NULL;
	while (parser->type != p_pip && parser->value != p_terminator)
	{
		if (parser->type == limiter)
			file_addback(&infile, addfile(parser));
		else if (parser->type == infile)
			file_addback(&infile, new_file(parser));
	}
}

void	get_infile(t_file *file, t_parser *parser)
{
	t_file *outfile;

	outfile = NULL;
	while (parser->type != p_pip && parser->value != p_terminator)
	{
		if (parser->type == limiter)
			file_addback(&infile, addfile(parser));
		else if (parser->type == infile)
			file_addback(&infile, new_file(parser));
	}
}
