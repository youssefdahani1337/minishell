/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/27 17:54:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_minishell(char *line)
{
	t_tokens	*token;

	token = NULL;
	ft_lexer(line, &token);
	t_tokens	*t = token;
	while (token)
	{
		printtoken(token);
		token = token->next;
	}
	ft_cleartoken(t);
}
