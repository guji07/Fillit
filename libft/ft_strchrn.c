/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:17:45 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/24 13:22:44 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrn(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\n')
	{
		if (s[i] == '\n')
			return (0);
		if (s[i] == (char)c)
			return (i);
		if (*s == '\0')
			return (0);
	}
	return (0);
}
