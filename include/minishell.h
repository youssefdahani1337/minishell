/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:12:28 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/23 18:55:51 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL_PROMPT "\033[0;32m[MiniShell] %> \033[0m"

# include "parser.h"
# include "../debug/debug.h"
# include <sys/types.h>
# include "multipipes.h"

int			ft_minishell(char *line);
int			ft_intialize_shell(char **env, int ac, char **av);

int			ft_execution(t_cmdtable *table);
int			ft_isbuiltins(t_cmdtable *table);
//end execution 

//fill struct 

char		*join_parser(t_parser **parser);
void		cmd_init(t_cmdtable *table);
void		fill_struct(t_cmdtable **table, t_parser *parser);
t_cmdtable	*add_table(t_parser **parser);
void		struct_addback(t_cmdtable **table, t_cmdtable *new);
int			count_t_parse(t_parser *parser);
void		get_cmd(t_cmdtable *cmd, t_parser *parser);
void		get_outfile(t_file **file, t_parser *parser);
void		skip_parse(t_parser **parser);
void		file_addback(t_file **files, t_file *new);
t_file		*new_file(int fd, char *msg);
t_file		*open_file(t_parser *parser, int *status);
t_file		*addfile(t_parser *parser);
void		fill_struct_iter(t_cmdtable **table, t_parser *parser);
void		skip_y_close(t_cmdtable *table);
void		skip_file(t_file **f, void *node, int std);
void		free_file(t_file *f);
void		free_cmd(t_cmdtable *table);

#endif