/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interperter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:22:49 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 12:43:56 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_parser	*parser;

	parser = NULL;
	token = NULL;
	if (check_space(line))
		return (free(line), 1);
	if (!ft_lexer(line, &token))
		return (0);
	if (ft_parser(&parser, token))
		return (0);
	fill_struct(&g_shell.table, parser);
	ft_execution(g_shell.table);
	free_cmd(g_shell.table);
	return (1);
}
