/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:00:46 by hbenabad          #+#    #+#             */
/*   Updated: 2023/06/24 21:15:26 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPIPES_H
# define MULTIPIPES_H
# include <sys/wait.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include "../libft/libft.h"
# include "structs.h"
# include "builtins.h"

char	*ft_modify_path(char *path_val);
char	**ft_checkpath(char **path);
int		ft_close(int **pipe, int size);
char	*ft_getcmdpath(char *cmd, char **path);
int		ft_slash_dot(char *cmd);
void	ft_check_dir(char *cmd);
char	*ft_check_cmd(char **cmd, char **path);
void	ft_execute_cmd(char *cmdpath, t_cmdtable *table, int size);
int		**ft_pipe(int size);
void	ft_child(t_cmdtable *table, char **path, int size, int pipe_index);
int		ft_forking(t_cmdtable *table, char **path, int **pipe, int size);
int		ft_wait_childs(t_cmdtable *table, int childs);
int		ft_multipipes(t_cmdtable *table);
int		ft_access_check(char *cmd);

#endif