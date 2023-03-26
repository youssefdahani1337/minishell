/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:48:24 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 15:54:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include <stdio.h>

# include "minishell.h"

typedef struct s_expnad
{
	char	*value;
	size_t	i;
	char	c;
	size_t	size;
}	t_expand;

t_expand	*init_expand(char *value);
char		*ft_expander(t_env *env, char	*value);
#endif