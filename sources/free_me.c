/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:23:14 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/12 20:27:20 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	skip_y_close(t_cmdtable *table)
{
	t_cmdtable	*tmp;

	tmp = NULL;
	while (table)
	{
		skip_file(&table->in, tmp, 0);
		skip_file(&table->out, table->next, 1);
		tmp = table;
		table = table->next;
	}
}

void	skip_file(t_file **f, void *node, int std)
{
	t_file	*tmp;
	t_file	*del;

	tmp = *f;
	if (!*f)
	{
		if (node)
			*f = new_file(-2, NULL);
		else
			*f = new_file(std, NULL);
		return ;
	}
	while (tmp->next)
	{
		del = tmp;
		tmp = tmp->next;
		free_file(del);
	}
	*f = tmp;
}

void	free_file(t_file *f)
{
	if (!f)
		return ;
	if (f->fd > 2)
		close(f->fd);
	if (f->error)
		free(f->error);
	free(f);
}

void	free_cmd(t_cmdtable *table)
{
	t_cmdtable	*tmp;

	while (table)
	{
		tmp = table->next;
		free_sp(table->cmd);
		free_file(table->in);
		free_file(table->out);
		free(table);
		table = tmp;
	}
}
