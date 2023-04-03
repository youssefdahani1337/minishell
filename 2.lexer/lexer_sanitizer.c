/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sanitizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:10:47 by yodahani          #+#    #+#             */
/*   Updated: 2023/04/02 15:13:38 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

t_tokens	*lexer_str(t_lexer *lexer)
{
	char	*value;

	value = malloc(sizeof(char));
	if (!value)
		return (NULL);
	value[0] = '\0';
	while (lexer->c != '\0' && !ft_strchr(" <>|'\"", lexer->c))
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	return (ft_newtoken(value, string));
}

t_tokens	*lexer_red(t_lexer *lexer)
{
	unsigned	int	i;

	i = lexer->i + 1 ; 
	if (lexer->c == red_in)
	{
		if (i < lexer->size)
		{
			if (lexer->src[i] == red_in)
				return (lexer_iter(lexer), ft_newtoken(ft_strdup("<<"), herdoc));	
		}
		return (ft_newtoken(ft_strdup("<"), red_in));
	}
	else
	{
		if (i < lexer->size)
		{
			if (lexer->src[i] == red_out)
				return (lexer_iter(lexer), ft_newtoken(ft_strdup(">>"), red_app));	
		}
		return (ft_newtoken(ft_strdup(">"), red_out));
	}
}

t_tokens	*lexer_quote(t_lexer *lexer)
{
	char	c;
	char	*value;

	value = ft_strdup("");
	c = lexer->c;
	lexer_iter(lexer);
	while (lexer->c != c)
	{
		value = ft_join_char(value, lexer->c);	
		lexer_iter(lexer);
	}
	return (ft_newtoken(value, c));
}