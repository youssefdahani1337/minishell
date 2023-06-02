/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:51:22 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/31 19:38:49 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	fill_struct(t_cmdtable **g_shell.table, t_parser *parser)
{
	*g_shell.table = NULL; 	
	while (parser->type != p_terminator)
	{
		strcuct_addback(g_shell.table, addtable(parser));
	}
	//revise
}

t_cmdtable	*add_table(t_parser **parser)
{
	t_cmdtable *cmd;

	cmd = malloc(sizeof(t_cmdtable));
	if (!cmd)
		return (NULL);
	t_cmd(&cmd->cmd, *parser);
	get_infile(&cmd->infile, *parser);
	get_outfile(&cmd->outfile, parser);
	skip_parse(parser);
	close_all_file(cmd);
}

void	struct_addback(t_cmdtable **table, t_cmdtable *new)
{
	t_cmdtable *tmp;

	tmp = *table;
	if (!*table)
		*table = new;
	else 
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}