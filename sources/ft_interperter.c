/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/29 15:52:07 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include "../debug/debug.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_tokens	*t;
	t_parser	*parser;

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
	fill_struct(&g_shell.table, parser);
	return (1);
}
