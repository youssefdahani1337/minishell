/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:42:06 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/25 15:08:55 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_type
{
	pip = '|',
	d_quote = '\"',
	s_quote = '\'',
	red_in = '<',
	red_out = '>',
	var = '$',
	var_ex = '?',
	red_app,
	herdoc,
	string,
	equal = '=',
	equal_plus = '+',
	terminator
}	t_type;

typedef struct s_tokens
{
	char			*value;
	t_type			type;
	int				join;
	struct s_tokens	*next;
}		t_tokens;

void		ft_lexer(char *line, t_tokens **t);
void		ft_tokenadd_back(t_tokens **tokens, t_tokens *new);
t_tokens	*ft_newtoken(char *value, int type, int join);
void		free_token(t_tokens *t);
void		free_lsttokens(t_tokens *t);
void		ft_cleartoken(t_tokens *t);
#endif