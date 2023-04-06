/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:20 by hbenabad          #+#    #+#             */
/*   Updated: 2023/04/04 16:34:55 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_change_pwds(t_env *p, char *opwd, int to_print, t_shell *gn_shell)
{
	char	pwd[128];

	getcwd(pwd, 128);
	while (p)
	{
		if (!ft_strcmp(p->key, "OLDPWD"))
		{
			free(p->value);
			p->value = ft_strdup(opwd);
		}
		else if (!ft_strcmp(p->key, "PWD"))
		{
			free(p->value);
			p->value = ft_strdup(pwd);
			if (to_print == 1)
			{
				ft_putstr_fd(p->value, (gn_shell->table)->outfile->fd);
				ft_putchar_fd('\n', (gn_shell->table)->outfile->fd);
			}
		}
		p = p->next;
	}
}

char	*ft_find_opwd(t_env *p)
{
	while (p)
	{
		if (ft_strcmp(p->key, "OLDPWD"))
			p = p->next;
		else
			return (p->value);
	}
	return (NULL);
}

void	ft_cd(t_shell *gn_shell)
{
	char	opwd[128];
	char	*dir;
	int		to_print;

	to_print = 0;
	getcwd(opwd, 128);
	dir = *((gn_shell->table)->cmd + 1);
	if (ft_strcmp(dir, "-") == 0)
	{
		dir = ft_find_opwd(gn_shell->env);
		if (dir == NULL)
		{
			ft_putstr_fd("minishell: cd : OLDPWD not set\n", 2);
			g_shell.exitsts = 1;
			return ;
		}
		to_print = 1;
	}
	if (chdir(dir) != 0)
	{
		ft_msgexitsts(dir, errno);
		return ;
	}
	ft_change_pwds(gn_shell->env, opwd, to_print);
}
