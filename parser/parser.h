/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:44:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/21 18:15:35 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../sources/minishell.h"
# define SP_CHAR	"\"|'<> "

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
void		ft_cleartoken(t_tokens *t);
void		join_str(t_tokens **t, char *line, int start, int i);
void		ft_exit_lexer(t_tokens **t, char *line, char *msg);
void		ft_red_find(t_tokens **t, char *line, int *i);
void		ft_quote_find(t_tokens **t, char *line, int *i);
void		ft_var_find(t_tokens **t, char *line, int *i);
void		free_token(t_tokens *t);
void		free_lsttokens(t_tokens *t);
char		*ft_find_var_quote(char *str);
t_tokens	*split_var(char *line, int *i);
void		free_lsttokens(t_tokens *t);
void		free_token(t_tokens *t);

#endif