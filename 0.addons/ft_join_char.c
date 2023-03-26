/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:36:50 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 11:33:02 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "addons.h"

char	*ft_join_char(char *value, char c)
{
	char		*str ;
	unsigned int	i;
	
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(value) + 2));
	if (!str)
		return(NULL);
	while (value[i])
	{
		str[i] = value[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	free(value);
	return (str);
}
