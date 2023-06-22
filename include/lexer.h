/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:44:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/22 11:23:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "token.h"

typedef struct s_lexer
{
	char			*src;
	unsigned int	i;
	char			c;
	size_t			size;
}	t_lexer;

int			lexer_syntax(t_lexer *lexer);
int			quote_close(t_lexer *lexer);
t_lexer		*init_lexer(char *line);	
int			ft_lexer(char *line, t_tokens **token);
t_tokens	*ft_next_token(t_lexer *lexer);
void		lexer_iter(t_lexer *lexer);
void		ft_skip_whitespace(t_lexer *lexer);
t_tokens	*lexer_forward(t_lexer *lexer, char *value, int type);
void		free_lexer(t_lexer *lexer);
t_tokens	*lexer_space(t_lexer *lexer);
t_tokens	*lexer_str(t_lexer *lexer);
t_tokens	*lexer_red(t_lexer *lexer);
t_tokens	*lexer_advance(t_lexer *lexer, t_tokens *token);
t_tokens	*lexer_quote(t_lexer *lexer);
void		trim_space(t_lexer *lexer);
#endif