/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:28 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 14:34:09 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*init_lexer(char *line)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->src = line;
	lexer->size = ft_strlen(line);
	lexer->i = 0;
	lexer->c = lexer->src[lexer->i];
	return (lexer);
}

void	ft_lexer(char *line, t_tokens **token)
{
	t_lexer		*lexer;
	t_tokens	*t;

	lexer = init_lexer(line);
	t = ft_next_token(lexer);
	while (t && t->type != terminator)
	{
		ft_tokenadd_back(token, t);
		if (t->type == error)
		{
			free(lexer);
			ft_exit_lexer(token, 0, t->value);
			return ;
		}
		t = ft_next_token(lexer);
	}
	free(t);
	free(lexer);
}

t_tokens	*ft_next_token(t_lexer *lexer)
{
	while (lexer->c != 0)
	{
		ft_skip_whitespace(lexer);
		if (!ft_strchr(" |<>\"'", lexer->c))
			return (ft_lexer_str(lexer));
		if (lexer->c == pip)
			return (lexer_forward(lexer, NULL, pip, 0));
		if (lexer->c == red_in || lexer->c == red_out)
			return (lexer_advance(lexer, lexer_red(lexer)));
		if (lexer->c == d_quote || lexer->c  == s_quote)
			return (lexer_advance(lexer, lexer_quote(lexer)));
	}
	return (ft_newtoken(NULL, terminator, 0));
}
