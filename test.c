/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:19:12 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/28 15:42:47 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
#include <unistd.h>
int main(int ac, char **av)
{
	if (ac < 0  || !av)
		return (0);
	char 	s[100];
	chdir("/tmp");
	printf("%s\n", getcwd(s, 100));
		while (1)
			;
	printf("%d\n", ft_strcmp(av[1], av[2]));
	return (0);
}