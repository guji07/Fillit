/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:07:42 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/11 23:19:56 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	j;
	size_t	i;
	char	*rev;

	i = ft_strlen(s);
	if (!(rev = (char *)ft_memalloc(sizeof(char) * i)))
		return (NULL);
	j = 0;
	i--;
	while (i + 1 != 0)
		rev[j++] = s[i--];
	return (rev);
}
