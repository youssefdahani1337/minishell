/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:27:14 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/07 19:42:56 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

void	lexer_iter(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < lexer->size)
	{
		lexer->i ++;
		lexer->c = lexer->src[lexer->i];
	}
}

void	ft_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c != '\0' && ft_strchr(" \t\n", lexer->c))
		lexer_iter(lexer);
}

t_tokens	*lexer_forward(t_lexer *lexer, char *value, int type)
{
	lexer_iter(lexer);
	return (ft_newtoken(value, type));
}

t_tokens	*lexer_advance(t_lexer *lexer, t_tokens *token)
{
	lexer_iter(lexer);
	return (token);
}

void	free_lexer(t_lexer *lexer)
{
	free(lexer->src);
	free(lexer);
}
