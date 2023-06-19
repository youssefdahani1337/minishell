/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:28:03 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/19 19:27:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (!s1)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (0);
	while (i <= ft_strlen(s1))
	{
		str[i] = s1[i];
		i ++;
	}
	return (str);
}
