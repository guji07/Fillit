/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:59:59 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/09 13:34:28 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wh_counter(const char *s)
{
	size_t end;
	size_t i;
	size_t i2;

	end = 0;
	i = 0;
	i2 = 0;
	while (s[end])
		end++;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (end > i && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		end--;
		i2++;
	}
	return (i2 + i);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	end;
	size_t	i;

	if (!s + (i = 0))
		return (NULL);
	len = ft_strlen(s) - wh_counter(s);
	if (ft_strlen(s) == wh_counter(s))
	{
		if (!(trim = (char *)ft_memalloc(sizeof(char))))
			return (NULL);
		return (trim);
	}
	len = 0;
	while (s[len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end)
		end--;
	if (!(trim = (char *)ft_memalloc(sizeof(char) * (end - len + 2))))
		return (NULL);
	while (len <= end)
		trim[i++] = s[len++];
	return (trim);
}
