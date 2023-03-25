/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:28 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/25 14:51:02 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*init_lexer(const char *line)
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

void	ft_lexer(char *line, t_tokens **t)
{
	t_lexer	*lexer;
	t_lexer	
	lexer = init_lexer(line);
	
	while ()
}


void	ft_exit_lexer(t_tokens **t, char *line, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_cleartoken(*t);
	free(line);
	exit(1);
}
