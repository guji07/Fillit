/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:26:01 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/17 15:26:49 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char	*dup;
	int		i;

	i = 0;
	while (s1[i] && i < len)
		i++;
	dup = (char *)ft_memalloc((sizeof(char)) * (i + 1));
	if (dup == 0)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] && i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
