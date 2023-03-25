/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:17:44 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/25 17:44:35 by hbenabad         ###   ########.fr       */
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
		ft_envadd_back(&env_info, ft_envnew(ft_infos(env[i]), i));
		i++;
	}
	return (env_info);
}

void	ft_echo(char **str)
{
	int	i;
	int	j;
	int	k;
	int	end;

	i = 1;
	end = 1;
	if (!str)
		return ;
	while (str[i] && str[i][j] && end == 1)
	{
		j = 0;
		if (str[i][j] == '-')
		{
			j++;
			while (str[i][j] && str[i][j] == 'n')
				j++;
			if (!str[i][j] && j > 1)
				i++;
			else if (str[i][j] || (!str[i][j] && j <= 1))
				end = 0;
		}
	}
	k = i;
	while (str[k])
	{
		ft_putstr_fd(str[k], 1);
		k++;
	}
	if (i > 1)
		ft_putchar_fd('\n', 1);
}

int	main(void)
{
	char	*str[6];

	str[0] = "echo";
	str[1] = "-nnnnn";
	str[2] = "-nn";
	str[3] = "-n";
	str[4] = "-nnnnnnk";
	str[5] = NULL;
	ft_echo(str);
}