/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:05:15 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 18:12:14 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executils.h"

int	ft_shlvl(void)
{
	t_env	*shlvl;
	int		shl;

	shl = 1;
	shlvl = ft_getenv("SHLVL");
	if (!shlvl)
	{
		shlvl = ft_envnew("SHLVL");
		if (!ft_envadd_back(&g_shell.env, shlvl))
			return (0);
	}
	if (shlvl->value)
	{
		shl = atoi_m(shlvl->value) + 1;
		free(shlvl->value);
	}
	shlvl->value = ft_itoa(shl);
	if (!shlvl->value)
	{
		ft_perr_sts();
		return (0);
	}
	shlvl->equal = 1;
	return (1);
}
