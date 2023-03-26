/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:29:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 16:02:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_expand	*init_expand(char *value)
{
	t_expand	*exp;

	exp = malloc(sizeof(t_expand));
	exp->value  = ft_strdup(value);
	exp->size = ft_strlen(value);
	exp->i = 0;
	exp->c = exp->value[];
	return (exp);
}

char	*ft_expander(t_env *env, char	*value)
{
	
}

char	*ft_getvar(t_env *env, char *value)
{
	char	*str;

	str = ft_strdup("");
	while 
}