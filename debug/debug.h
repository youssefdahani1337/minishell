/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:19:10 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/27 14:22:34 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../include/minishell.h"
# include "../include/token.h"

void	printdebug(void);
void	printtoken(t_tokens *token);

#endif 