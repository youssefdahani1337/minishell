/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:17:44 by hbenabad          #+#    #+#             */
/*   Updated: 2023/03/25 14:43:40 by hbenabad         ###   ########.fr       */
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
	env_info = malloc(sizeof(t_env));
	if (!env_info)
		return (NULL);
	while (env[i])
	{
		ft_envadd_back(&env_info, ft_envnew(ft_infos(env[i]), i));
		printf("hello\n"); 
		i++; //didn't use split cuz some vars have many '='
	}
	return (env_info);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*env_info;

	(void)argc;
	(void)argv;
	env_info = ft_env(env);
	while (env_info)
	{
		printf("%s\n%s\n%d\n%d", env_info->var, env_info->value, env_info->rank, env_info->equal);
		env_info = env_info->next;
	}
	return (0);
}
// void	ft_echo(char **str)
// {
	
// }