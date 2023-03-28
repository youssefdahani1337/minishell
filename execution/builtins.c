/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:17:44 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/28 18:27:06 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_env	*ft_env(char **env)
{
	int		i;
	int		j;
	t_env	*env_info;

	i = 0;
	j = 0;
	env_info = NULL;
	while (env[i])
	{
		if (ft_envadd_back(&env_info, ft_envnew(env[i])) == 0)
			return (NULL);
		i++;
	}
	return (env_info);
}

void	ft_echo(char **str)
{
	int	index;
	int	k;

	index = ft_flag_ignore(str);
	if (index == 0)
		return ;
	k = index; //it prints env if argv not given
	while (str[k])
	{
		ft_putstr_fd(str[k], 1);
		k++;
		if (str[k])
			ft_putstr_fd(" ", 1);
	}
	if (index <= 1)
		ft_putchar_fd('\n', 1);
}

void	ft_cd(char **str, t_env *p)
{
	char	*opwd;
	char	s[100];
	char	*pwd;

	opwd = getcwd(s, 100);
	if (opwd == NULL)
		perror("getcwd:");
	if (ft_strncmp(str[1], "-", 1) == 0)
		str[1] = opwd;
	//if (str[1] == "~")
	if (chdir(str[1]) != 0)
		perror(str[1]);
	pwd = getcwd(s, 100);
	if (pwd == NULL)
		perror("getcwd:");
	ft_change_pwds(p, opwd, pwd);
}

void	ft_pwd(void)
{
	char	s[100];
	char	*pwd;

	pwd = getcwd(s, 100);
	if (pwd == NULL)
		perror("getcwd:");
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_export(t_env	*env_info)
{
	int		i;
	t_env	*p;
	int		len;
	int		done;

	i = 0;
	done = 0;
	p = env_info;
	len = ft_rank_env(p);
	while (p)
	{
		if (ft_strncmp(p->key, "-", 2) == 0 && done == 0)
		{
			p->next->rank = p->rank;
			p->rank = -1;
			done = 1;
		}
		else if (p->rank == i)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(p->key, 1);
			if (p->equal == 1)
				ft_putstr_fd("=", 1);
			if (p->value != NULL)
			{
				ft_putchar_fd('"', 1);
				ft_putstr_fd(p->value, 1);
				ft_putchar_fd('"', 1);
			}
			ft_putstr_fd("\n", 1);
			p = env_info;
			i++;
		}
		else
			p = p->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_env	*p;

	p = ft_env(env);
	ft_export(p);
}
