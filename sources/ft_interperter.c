/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/28 15:42:30 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_tokens	*t;
	t_parser	*parser;
	t_cmdtable	*cmd;
	parser = NULL;
	token = NULL;
	if (!ft_lexer(line, &token))
		return (0);
	t = token; 
	while (t)
	{
		printtoken(t);
		t = t->next;
	}
	printf("\n++++++++++++++++\n");
	if (!ft_parser(&parser, token))
		return (0);
	
	while (parser)
	{
		printparser(parser);
		parser = parser->next;
	}
	cmd = g_shell.table;
	ft_execution(cmd);
	freecmd(g_shell.table);
	return (1);
}
