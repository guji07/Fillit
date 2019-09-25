/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:20:42 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/08 18:28:47 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (n == 0 || (unsigned char *)dst == (unsigned char *)src)
		return (dst);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
