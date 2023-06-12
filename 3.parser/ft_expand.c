/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:29:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/12 10:59:35 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/expand.h"

char	*ft_exp(char *value)
{
	t_expand	*exp;

	if (!value)
		return (NULL);
	exp = init_expand(value);
	if (exp->c == '~')
		exp_tilde(exp);
	while (exp->c != '\0')
	{
		if (exp->c != '$')
		{
			exp->newstr = ft_join_char(exp->newstr, exp->c);
			expand_iter(exp);
		}
		else
			ft_getvar(exp);
	}
	value = exp->newstr;
	free_exp(exp);
	return (value);
}

void	ft_getvar(t_expand *exp)
{
	expand_iter(exp);
	if (exp->c == '?')
	{
		exp->newstr = ft_strjoin_m(exp->newstr, ft_itoa(g_shell.exitsts));
		expand_iter(exp);
	}
	else if (ft_isdigit(exp->c))
	{
		exp->newstr = ft_strjoin_m(exp->newstr, ft_strdup(""));
		expand_iter(exp);
	}
	else if (ft_isalpha(exp->c) || exp->c == '_')
		get_from_env(exp);
	else if (exp->c == '$')
		expand_iter(exp);
	else
		exp->newstr = ft_join_char(exp->newstr, '$');
}

void	get_from_env(t_expand *exp)
{
	char	*key;

	key = ft_strdup("");
	while (exp->c != '\0' && (ft_isalnum(exp->c) || exp->c == '_'))
	{
		key = ft_join_char(key, exp->c);
		expand_iter(exp);
	}
	exp->newstr = ft_strjoin_m(exp->newstr, get_env_val(key));
	free(key);
}

char	*get_env_val(char *key)
{
	t_env	*env;

	env = g_shell.env;
	while (env)
	{
		if (ft_strcmp(key, env->key) == 0)
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

void	exp_tilde(t_expand *exp)
{
	expand_iter(exp);
	if (exp->c == '\0' || exp->c == '/')
		exp->newstr = ft_strjoin_m(exp->newstr, get_env_val("HOME"));
}
