/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:30:04 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 21:15:12 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

void	ft_check_dir(char *cmd)
{
	struct stat	buf;

	if (stat(cmd, &buf) == -1)
		return ;
	if (S_ISDIR(buf.st_mode))
		ft_pipes_msg(cmd, "is a directory", 126);
}
