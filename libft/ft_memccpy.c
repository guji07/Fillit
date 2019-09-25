/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:53:07 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/08 18:41:04 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
