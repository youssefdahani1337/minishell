/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:29:19 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/10 15:50:24 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_delenvnode(t_env *to_unset)
{
	to_unset->next = NULL;
	free(to_unset->key);
	free(to_unset->value);
	free(to_unset);
	return ;
}

int	ft_checkvar(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_unset_str(t_env **ptr, t_env *env_var, char *cmd_str)
{
	t_env	*to_unset;

	while (env_var)
	{
		if (!ft_strcmp(env_var->key, cmd_str))
		{
			to_unset = env_var;
			*ptr = to_unset->next;
			env_var = *ptr;
			ft_delenvnode(to_unset);
			break ;
		}
		else
		{
			ptr = &(env_var->next);
			env_var = env_var->next;
		}
	}
}

void	ft_unset(t_cmdtable *table)
{
	char	**cmd_str;
	int		i;

	i = 0;
	cmd_str = table->cmd + 1;
	while (cmd_str[i])
	{
		if (!ft_checkvar(cmd_str[i]))
		{
			printf("unset: %s: invalid parameter name\n", cmd_str[i]);
			g_shell.exitsts = 1;
		}
		else
		{
			if (!ft_strcmp(cmd_str[i], "PWD"))
				g_shell.unsetpwd = 1;
			ft_unset_str(&g_shell.env, g_shell.env, cmd_str[i]);
		}
		i++;
	}
	return ;
}
