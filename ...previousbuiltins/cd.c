/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:20 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:19 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_change_pwds(t_env *p, char *opwd, int to_print)
{
	char	pwd[128];

	if (!getcwd(pwd, 128))
	{
		perror("minishell");
		return ;
	}
	while (p)
	{
		if (opwd)
		{
			if (!ft_strcmp(p->key, "OLDPWD"))
			{
				free(p->value);
				p->value = ft_strdup(opwd);
				if (!p->value)
				{
					perror("minishell");
					return ;
				}
			}
		}
		else if (!ft_strcmp(p->key, "PWD"))
		{
			free(p->value);
			p->value = ft_strdup(pwd);
			if (!p->value)
			{
				perror("minishell");
				return ;
			}
			if (to_print == 1)
			{
				// ft_putstr_fd(p->value, (g_shell.table)->outfile->fd);
				// ft_putchar_fd('\n', (g_shell.table)->outfile->fd);
				ft_putstr_fd(p->value, 1);
				ft_putchar_fd('\n', 1);
			}
		}
		p = p->next;
	}
}

char	*ft_find_opwd(t_env *p)
{
	while (p)
	{
		if (ft_strcmp(p->key, "OLDPWD") == 0)
			return (p->value);
		p = p->next;
	}
	return (NULL);
}

void	ft_cd(char **str, t_env *env)
{
	char	opwd[128];
	int		to_print;
	char	*dir;

	to_print = 0;
	getcwd(opwd, 128);
	// dir = (g_shell.table)->cmd + 1;
	dir = str[2];
	if (!ft_strcmp(dir, "-"))
	{
		// opwd_infos = ft_find_opwd(gn_shell->env);
		dir = ft_find_opwd(env);
		if (dir == NULL)
		{
			ft_msgexitsts("cd : OLDPWD not set\n", 1);
			return ;
		}
		to_print = 1;
	}
	if (dir && dir[0] && chdir(dir))
	{
		perror("minishell        ");
		return ;
	}
	// ft_change_pwds(g_shell.env, opwd, to_print);
	ft_change_pwds(env, opwd, to_print);
}
