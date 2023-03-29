/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:41:20 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/29 16:36:33 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_change_pwds(t_env *p, char *opwd, char *pwd)
{
	int	cmp_p;
	int	cmp_op;

	cmp_p = 1;
	cmp_op = 1;
	while (p)
	{
		if (cmp_op != 0)
		{
			cmp_op = ft_strncmp (p->key, "OLDPWD", ft_strlen(p->key));
			if (cmp_op == 0)
				p->value = opwd;
		}
		else if (cmp_p != 0)
		{
			cmp_p = ft_strncmp(p->key, "PWD", ft_strlen(p->key));
			if (cmp_p == 0)
				p->value = pwd;
		}
		p = p->next;
	}
}

void	ft_cd(void)
{
	char	*opwd;
	char	s[100];
	char	*pwd;
	char	**str;
	t_env	*p;

	p = g_shell->env;
	opwd = getcwd(s, 100);
	if (!opwd)
		return (NULL);
	str = g_shell.table->cmd;
	if (ft_strcmp(str[1], "-") == 0)
	{
		if (opwd == NULL)
			perror("getcwd:");
		str[1] = opwd;
	}
	if (chdir(str[1]) != 0)
		perror(str[1]);
	pwd = getcwd(s, 100);
	if (pwd == NULL)
		perror("getcwd:");
	ft_change_pwds(p, opwd, pwd);
}
