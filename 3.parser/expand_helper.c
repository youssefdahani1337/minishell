/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:23:54 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 09:17:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/expand.h"

t_expand	*init_expand(char *value)
{
	t_expand	*exp;

	exp = malloc(sizeof(t_expand));
	exp->value = value;
	exp->size = ft_strlen(value);
	exp->newstr = ft_strdup("");
	exp->i = 0;
	exp->c = exp->value[exp->i];
	return (exp);
}

void	expand_iter(t_expand *exp)
{
	if (exp->i < exp->size && exp->c != '\0')
	{
		exp->i ++;
		exp->c = exp->value[exp->i];
	}
}

void	free_exp(t_expand *exp)
{
	free(exp->value);
	free(exp);
}
