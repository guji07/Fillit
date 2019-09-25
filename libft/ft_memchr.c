/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:47:22 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/08 20:16:16 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char ch;

	ch = (unsigned char)c;
	str = (unsigned char*)s;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
