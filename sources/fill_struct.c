/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:51:22 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/10 10:16:44 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cmd_init(t_cmdtable *table)
{
	table->cmd = NULL;
	table->in = NULL;
	table->out = NULL;
	table->next = NULL;
}

void	fill_struct(t_cmdtable **table, t_parser *parser)
{
	*table = NULL;
	fill_struct_iter(table, parser);
	ft_clearparse(parser);
	skip_y_close(*table);
}

void	fill_struct_iter(t_cmdtable **table, t_parser *parser)
{
	*table = NULL;
	while (parser->type != p_terminator)
		struct_addback(table, add_table(&parser));
}

t_cmdtable	*add_table(t_parser **parser)
{
	t_cmdtable	*cmd;

	cmd = malloc(sizeof(t_cmdtable));
	if (!cmd)
		return (NULL);
	cmd_init(cmd);
	get_cmd(cmd, *parser);
	skip_parse(parser);
	return (cmd);
}

void	struct_addback(t_cmdtable **table, t_cmdtable *new)
{
	t_cmdtable	*tmp;

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
