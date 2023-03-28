/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:17:44 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/28 15:37:09 by hbenabad         ###   ########.fr       */
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

void	ft_cd(char **str, t_env **env_info)
{
	char	*opwd;
	char	s[100];
	int		cmp_p;
	int		cmp_op;
	t_env	*p;
	char	*pwd;

	p = *env_info;
	opwd = getcwd(s, 100);
	if (chdir(str[1]) != 0)
		perror(str[1]);
	pwd = getcwd(s, 100);
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

int	main(int argc, char **argv, char **env)
{
	t_env	*env_info;
	// t_env	*p;

	(void)argc;
	env_info = ft_env(env);
	//ft_echo(argv + 1);
	
	ft_cd(argv + 1, &env_info);
	// p = env_info;
	// while (p)
	// {
	// 	ft_printf("%s=%s\n", p->key, p->value);
	// 	p = p->next;
	// }
	return (0);
}
