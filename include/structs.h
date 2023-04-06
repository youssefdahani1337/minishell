/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:07:38 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/29 14:38:37 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	char			*key;
	char			*value;
	int				rank;
	int				equal;
	struct s_env	*next;
}	t_env;

typedef struct s_file
{
	int				fd;
	int				type;
	struct s_file	*next;
}	t_file;

typedef struct	s_cmdtable
{
	char				**cmd;
	t_file				*infile;
	t_file				*outfile;
	struct s_cmdtable	*next;
}	t_cmdtable;

typedef struct	s_shell
{
	t_env		*env;
	t_cmdtable	*table;
	int			exitsts;
}	t_shell;
t_shell 	g_shell;

#endif