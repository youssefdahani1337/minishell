/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:00:54 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/05 11:55:04 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


# include "lexer.h"
# include "expand.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef	enum	e_type_p
{
	limiter,
	infile,
	outfile,
	appfile,
	p_string,
	p_pip,
	p_error,
	p_space,
	p_terminator
}	t_type_p;

typedef struct s_parser
{
	t_type_p		type;
	int				state;
	char			*value;
	struct s_parser	*next;
}	t_parser;

int			ft_parser(t_parser **parser, t_tokens *token);
int			parser_parse(t_parser **parser, t_tokens *token);
int			open_heredoc(t_parser *parser);
void		execute_heredoc(t_parser *parser);
void		write_in_her(char *line, int fd, int state);
int			get_typeparse(t_tokens *token);

t_parser	*ft_newparse(char *value, int type, int state);
void		ft_parseadd_back(t_parser **parser, t_parser *new);
void		ft_clearparse(t_parser *p);
void		free_parse(t_parser *p);
void		skipper_token(t_tokens **tokens);
char		*join_token(t_tokens **token, int *state);
void		parser_parsing(t_parser **parser, t_tokens **token, int *error);
void		parser_add_string(t_parser **parser, t_tokens **token);
void		add_str_parse(t_parser **parser, t_lexer *lexer);
void		add_space_parse(t_parser **parser, t_lexer *lexer);
void		parser_add_quote(t_parser **parser, t_tokens **token);
void		parser_add_herdoc(t_parser **parser, t_tokens **token, int *error);
void		add_parse(t_parser **parser, t_tokens **token);
int			in_join(int type, int *state);
void		parser_add_redirect(t_parser **parser, t_tokens **token, int *error);

char	*join_red(char *value, t_tokens *token, int *state);
char	*ft_join_exp(char *value, char *tok_str, int *state);


#endif