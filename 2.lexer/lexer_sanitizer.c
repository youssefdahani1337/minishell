/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sanitizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:10:47 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/25 18:05:50 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tokens	*ft_lexer_str(t_lexer *lexer)
{
	char	*value;

	value = malloc(sizeof(char));
	if (!value)
		return (value);
	value[0] = '\0';
	while (lexer->c != '\0' && !ft_strchr(" '\"<>|", lexer->c))
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	return (ft_newtoken(value, string, 0));
}

t_tokens	*lexer_red(t_lexer *lexer)
{
	if (lexer->c == red_in)
	{
		if (lexer->i + 1 < lexer->size)
		{
			lexer_iter(lexer);
			if (lexer->c == red_in)
				return (ft_newtoken(NULL, herdoc, 0));	
			return (ft_newtoken(NULL, red_in, 0));	
		}
			return (ft_newtoken(NULL, red_in, 0));
	}
	else
	{
		if (lexer->i + 1 < lexer->size)
		{
			lexer_iter(lexer);
			if (lexer->c == red_out)
				return (ft_newtoken(NULL, red_app, 0));	
			return (ft_newtoken(NULL, red_out, 0));
		}
		return (ft_newtoken(NULL, red_out, 0));
	}
}

t_token		*lexer_quote(t_lexer)
{
	
	
}