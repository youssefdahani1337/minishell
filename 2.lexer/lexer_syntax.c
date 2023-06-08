/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:10:43 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/06 11:03:43 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"


int	lexer_syntax(t_lexer *lexer)
{
	int	i;

	i = lexer->size - 1;
	if (lexer->c == pip || (lexer->size > 0 && lexer->src[i] == pip))
		return (print_error("syntax error near unexpected token", "|"));
	while (lexer->c != '\0')
	{
		if (lexer->c == '\'' || lexer->c == '\"')
		{
			if (quote_close(lexer) == 0)
				print_error("Unclosed quote!!", NULL);
		}
		lexer_iter(lexer);
	}
	return (1);
}

int	quote_close(t_lexer *lexer)
{
	char	c;

	c = lexer->c;
	lexer_iter(lexer);
	while (lexer->c)
	{
		if (c == lexer->c)
			return (1);
		lexer_iter(lexer);
	}
	return (0);
}
