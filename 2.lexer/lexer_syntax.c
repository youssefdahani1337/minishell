/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:10:43 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/22 16:23:51 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

int	lexer_syntax(t_lexer *lexer)
{
	int	i;

	trim_space(lexer);
	i = lexer->size - 1;
	if (lexer->c == pip || (lexer->size > 0 && lexer->src[i] == pip))
	{
		free_lexer(lexer);
		return (print_error("syntax error near unexpected token", "|"));
	}
	while (lexer->c != '\0')
	{
		if (lexer->c == '\'' || lexer->c == '\"')
		{
			if (quote_close(lexer) == 0)
			{
				print_error("Unclosed quote!! ", NULL);
				free_lexer(lexer);
				return (0);
			}
		}
		lexer_iter(lexer);
	}
	free(lexer);
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

void	trim_space(t_lexer *lexer)
{
	int	size;

	ft_skip_whitespace(lexer);
	size = lexer->size - 1;
	while (size >= 0 && lexer->src[size] == space)
		size --;
	lexer->size = size + 1;
	lexer->src[size +1] = '\0';
}
