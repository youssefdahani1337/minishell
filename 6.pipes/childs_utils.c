/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:30:04 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 18:34:37 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/multipipes.h"

void	ft_check_dir(char *cmd)
{
	struct stat	buf;

	if (stat(cmd[0], &buf) == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (S_ISDIR(buf.st_mode))
		ft_pipes_msg(cmd[0], "is a directory", 126);
}
