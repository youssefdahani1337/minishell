/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:19:10 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 11:32:51 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "../include/minishell.h"

void	printdebug(void);
void	printtoken(t_tokens *token);
void	printparser(t_parser *parser);
void	print_cmd(t_cmdtable *cmd);

void	print_parser_iter(t_parser *parser);
void	print_token_iter(t_tokens *token);
void	print_cmd_iter(t_cmdtable *cmd);

#endif 