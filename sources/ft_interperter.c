/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/05 01:20:53 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	return (1);
}
