/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_s_adds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:56:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/14 17:38:45 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../debug/debug.h"

int	count_t_parse(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser->type != p_pip && parser->type != p_terminator)
	{
		if (parser->type == p_string)
			i ++;
		parser = parser->next;
	}
	return (i);
}

void	get_cmd(t_cmdtable *cmd, t_parser *parser)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	cmd->cmd = (char **)malloc(sizeof(char *) * (count_t_parse(parser) + 1));
	while (parser && parser->type != p_pip && parser->type != p_terminator)
	{
		if (parser->type == p_string)
			cmd->cmd[i ++] = join_parser(&parser);
		else if (parser->type == limiter)
			file_addback(&cmd->in, addfile(parser));
		else if (parser->type == infile)
			file_addback(&cmd->in, open_file(parser, &status));
		else if (parser->type == outfile || parser->type == appfile)
			file_addback(&cmd->out, open_file(parser, &status));
		if (status == -1)
			break ;
		if (parser->type != p_string)
			parser = parser->next;
	}
	cmd->cmd[i] = NULL;
}

void	get_outfile(t_file **file, t_parser *parser)
{
	int	status;

	status = 0;
	*file = NULL;
	while (parser->type != p_pip && parser->type != p_terminator)
	{
		file_addback(file, open_file(parser, &status));
		if (status == -1)
			break ;
		parser = parser->next;
	}
}

void	skip_parse(t_parser **parser)
{
	while ((*parser)->type != p_pip && (*parser)->type != p_terminator)
		(*parser) = (*parser)->next;
	if ((*parser)->type == p_pip)
		(*parser) = (*parser)->next;
}

char	*join_parser(t_parser **parser)
{
	char	*value;

	value = ft_strdup("");
	while ((*parser)->type == p_string)
	{
		value = ft_strjoin_m(value, (*parser)->value);
		(*parser)->value = NULL;
		(*parser) = (*parser)->next;
			printparser((*parser));

	}
	return (value);
}
