/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:22:48 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/25 11:12:20 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	char			*key;
	char			*value;
	unsigned int	rank;
	struct s_env	*next;
}	t_env;

typedef struct	s_shell
{
	t_env	*env;
}	t_shell;


#endif