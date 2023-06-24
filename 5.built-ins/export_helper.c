/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:35:28 by mac               #+#    #+#             */
/*   Updated: 2023/06/24 12:08:16 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

char	*find_key(t_lexer *lexer)
{
	char	*value;

	value = NULL;
	if (lexer->c != '_' && !ft_isalpha(lexer->c))
		return (NULL);
	while (lexer->c == '_' || ft_isalnum(lexer->c))
	{
		value = ft_join_char(value, lexer->c);
		lexer_iter(lexer);
	}
	return (value);
}

char	find_type_exp(t_lexer *lexer)
{
	if (lexer->c == p_equal)
	{
		lexer_iter(lexer);
		if (lexer->c == equal)
			return (lexer_iter(lexer), p_equal);
		return (exp_error);
	}
	else if (lexer->c == equal)
		return (lexer_iter(lexer), equal);
	else if (!lexer->c)
		return (no_equal);
	return (exp_error);
}

char	*find_value(t_lexer *lexer, t_export *infos)
{
	char	*value;

	if (!lexer->c)
		return (NULL);
	if (infos->node && infos->node->value && infos->type == p_equal)
	{
		value = ft_strjoin_m(infos->node->value,
				ft_strdup(lexer->src + lexer->i));
		infos->node->value = NULL;
		return (value);
	}
	value = ft_strdup(lexer->src + lexer->i);
	return (value);
}

void	init_infos(t_export *infos)
{
	infos->key = NULL;
	infos->node = NULL;
	infos->value = NULL;
}
void	free_infos(t_export *infos)
{
	free(infos->key);
	free(infos->value);
}