/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:36:30 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/08 18:26:45 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && s++)
	{
		if (!*s && (char)c == '\0')
			return ((char *)s);
		if (*s == '\0')
			return (0);
	}
	return ((char *)s);
}
