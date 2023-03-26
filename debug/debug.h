/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:19:10 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 11:39:36 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../sources/minishell.h"
# include "../1.tokenizer/token.h"

void	printdebug(void);
void	printtoken(t_tokens *token);

#endif 