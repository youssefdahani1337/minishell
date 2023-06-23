/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addons.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:11:50 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/23 09:43:48 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDONS_H
# define ADDONS_H
# include <stdlib.h>
# include "structs.h"
# include <sys/errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>
# include <string.h>

void	rl_replace_line(const char *line, int n);
char	*ft_strjoin_m(char *s1, char *s2);
char	*ft_join_char(char *value, char c);
int		print_error(char *msg, char *speciel);
int		count_sp(char **sp);
void	free_sp(char **sp);
int		atoi_m(const char	*str);
int		check_space(const char *line);
void	hand(int sig);
void	remove_ctrl_c(void);
void	handler(int sig);
void	ft_errmsg_sts(char *cmd, char *str, char *err);
void	ft_perr_sts(void);
void	ft_pipes_msg(char *name, char *str, int exitsts);
int		ft_tablesize(t_cmdtable *table);
void	ft_freedptr(int **pipes, int size);
t_env	*ft_getenv(char *key);
void	ft_cmd_change(char **cmd);
void	exit_with_sig(int status);
void	handler_df(void);
#endif