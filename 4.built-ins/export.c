/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:46:17 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/18 23:16:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	ft_rank_lst(t_list **keylst)
{
	t_list	*p;
	t_list	*q;
	char	*str;
	int		len;

	p = *keylst;
	len = ft_strlen(p->content);
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (ft_strncmp(p->content, q->content, len) > 0)
			{
				str = p->content;
				p->content = q->content;
				q->content = str;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void	ft_ranker(t_env *env_info, t_list **keys_lst)
{
	t_list	*p;
	int		i;
	int		done;
	int		len;

	while (env_info)
	{
		i = 0;
		p = *keys_lst;
		done = 0;
		len = ft_strlen(env_info->key);
		while (p && done == 0)
		{
			if (ft_strncmp(env_info->key, p->content, len) == 0)
			{
				env_info->rank = i;
				done = 1;
			}
			i++;
			p = p->next;
		}
		env_info = env_info->next;
	}
}

void	ft_rank_env(t_env *env_info)
{
	t_list	*keys_lst;
	t_env	*p;
	int		i;

	i = 0;
	p = env_info;
	keys_lst = NULL;
	while (p)
	{
		ft_lstadd_back(&keys_lst, ft_lstnew(p->key));
		i++;
		p = p->next;
	}
	ft_rank_lst(&keys_lst);
	ft_ranker(env_info, &keys_lst);
}

void	ft_export(t_cmdtable *table)
{
	if (!table->cmd[1])
	{
		ft_rank_env(g_shell.env);
		ft_display_export(table, g_shell.env);
	}
	else
		ft_changeadd_export(table->cmd + 1);
}

void	ft_display_export(t_cmdtable *table, t_env *p)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	while (p)
	{
		if (done == 0 && ft_strcmp(p->key, "_") == 0)
		{
			p = g_shell.env;
			i++;
			done = 1;
		}
		else if (p->rank == i)
		{
			ft_putstr_fd("declare -x ", table->out->fd);
			ft_putstr_fd(p->key, table->out->fd);
			if (p->equal == 1)
				ft_putstr_fd("=", table->out->fd);
			if (p->value != NULL)
			{
				ft_putchar_fd('"', table->out->fd);
				ft_putstr_fd(p->value, table->out->fd);
				ft_putchar_fd('"', table->out->fd);
			}
			ft_putstr_fd("\n", table->out->fd);
			p = g_shell.env;
			i++;
		}
		else
			p = p->next;
	}
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
		infos->type = 1;
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
}`

