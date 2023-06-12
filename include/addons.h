/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addons.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:11:50 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/08 15:12:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDONS_H
# define ADDONS_H
# include <stdlib.h>
# include "structs.h"
# include <sys/errno.h>

char	*ft_strjoin_m(char *s1, char *s2);
char	*ft_join_char(char *value, char c);
int		print_error(char *msg, char *speciel);
int		count_sp(char **sp);
void	free_sp(char **sp);
int		atoi_m(const char	*str);

#endif