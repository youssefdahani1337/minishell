/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:36:49 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/10 15:06:40 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	i = 0;
	src1 = (char *) src;
	dst1 = (char *) dst;
	if (dst > src)
	{
		while (len --)
		{
			dst1[len] = src1[len];
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
