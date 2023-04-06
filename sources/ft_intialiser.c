/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intialiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:29:34 by yodahani          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/29 14:37:22 by hbenabad         ###   ########.fr       */
=======
/*   Updated: 2023/03/30 17:53:11 by yodahani         ###   ########.fr       */
>>>>>>> 0681aa5b2ff7ef3d68140a0de68f327762cc2923
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void	ft_intialize_shell(char **env)
{
	g_shell.env = ft_env(env);
	g_shell.exitsts = 0;
}