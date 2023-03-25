/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:44:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/25 14:49:23 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdio.h>
# include "../1.tokenizer/token.h"
# include "../libft/libft.h"

typedef	struct	s_lexer
{
	char			*src;
	unsigned int	i;
	char			c;
	size_t			size;
}	t_lexer;

t_lexer	*init_lexer(const char *line);

#endif