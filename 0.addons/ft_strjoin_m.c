/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:11:30 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/20 15:22:42 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "addons.h"

char	*ft_strjoin_m(char *s1, char *s2)
{
	char	*str;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
		str[j++] = s1[i ++];
	i = 0;
	while (s2 && s2[i])
		str[j++] = s2[i ++];
	str[j] = '\0';
	free(s1);
	free(s2);
	return (str);
}