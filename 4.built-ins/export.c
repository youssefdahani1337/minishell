/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:46:17 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/19 17:46:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_export(t_cmdtable *table)
{
	if (!table->cmd[1])
	{
		ft_rank_env();
		ft_export_display(g_shell.leader, table->out->fd);
	}
	else
		ft_changeadd_export(table->cmd + 1);
}

void	ft_changeadd_export(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_changeadd(arg[i]))
			ft_errmsg_sts("minishell: export: `", arg[i],
				"': not a valid identifier");
	}
}

void	ft_filladd(t_export *infos)
{	
	if (infos->type == equal || infos->type == p_equal)
		infos->type = true_equal;
	if (!infos->node)
	{
		infos->node = newenv(infos);
		ft_envadd_back(&g_shell.env, infos->node);
	}
	else if (infos->type)
	{
		infos->node->equal = infos->type;
		infos->node->value = infos->value;
	}
}

int		ft_changeadd(char *arg)
{
	t_lexer		*lexer;
	t_export	*infos;

	lexer = init_lexer(arg);
	if (!lexer)
		return (0);
	infos = malloc(sizeof(t_export));
	if (!infos)
		return (0);
	infos->key = find_key(lexer);
	if (!infos->key)
		return (0);
	infos->type = find_type_exp(lexer);
	if (infos->type == exp_error)
		return (0);
	infos->node = ft_getenv(infos->key);
	infos->value = find_value(lexer, infos);
	ft_filladd(infos);
	free(lexer);
	free(infos);
	return (1);
}
