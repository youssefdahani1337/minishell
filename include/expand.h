/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:48:24 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/27 14:32:08 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include <stdio.h>

# include "minishell.h"
# include "structs.h"

typedef struct s_expnad
{
	char	*value;
	char	*newstr;
	size_t	i;
	char	c;
	size_t	size;
	
}	t_expand;

t_expand	*init_expand(char *value);
char		*ft_expander(char *value);
void		get_from_env(t_expand *exp);
void		expand_iter(t_expand *exp);
char		*get_env_val(char *key);
void		free_exp(t_expand *exp);
void		ft_getvar(t_expand *exp);
#endif