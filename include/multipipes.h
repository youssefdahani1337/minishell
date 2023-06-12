/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:00:46 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/12 20:18:00 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPIPES_H
# define MULTIPIPES_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/errno.h>
# include <sys/param.h>
# include "../libft/libft.h"
# include "../include/structs.h"
# include "../include/builtins.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>

int		ft_isbuiltins(t_cmdtable *table);
int		ft_multipipes(t_cmdtable *table);
char	*ft_modify_path(char *path_val);
char	**ft_checkpath(char **path);
void	ft_pipes_msg(char *name, char *str, int exitsts);
char	*ft_getcmdpath(char *cmd, char **path);
int		ft_slash_dot(char *cmd);
char	*ft_check_cmd(char **cmd, char **path);
void	ft_child(t_cmdtable *cmd, char **path, int id, int read);
void	ft_execute_cmd(char *cmdpath, t_cmdtable *table, int read);
void	ft_exec_onecmd(char *cmdpath, t_cmdtable *table);
int		ft_fork_one(t_cmdtable *table, char **path);
int		ft_forking(t_cmdtable *table, char **path, int *fds);

#endif