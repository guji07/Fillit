/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:32:32 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/08 20:01:17 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((s1[i] == s2[i]) && i < n && s1[i] && s2[i])
		i++;
	if (n == i)
		--i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
