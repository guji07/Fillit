/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:25:26 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/11 22:38:29 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	while (s[i])
	{
		i++;
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i])
				count++;
		}
	}
	return (count + 2);
}

static int		sym(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char		*ft_new(char *s, char **str, int index, char c)
{
	char	*new;
	size_t	j;

	if ((new = (char *)ft_memalloc(sym(s, c) + 1)))
		ft_strncpy(new, s, sym(s, c));
	else
	{
		j = index;
		while (j > 0)
		{
			ft_strdel(&str[j]);
			j--;
		}
		free(str);
	}
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (c == '\0')
		return ((char **)ft_memalloc(1));
	if (!s)
		return (NULL);
	if ((str = (char **)ft_memalloc(sizeof(char **) * word(s, c))))
	{
		while (s[i])
		{
			if (s[i] != c)
			{
				str[j] = ft_new((char *)s + i, str, j, c);
				i += (ft_strlen(str[j]) - 1);
				j++;
			}
			i++;
		}
	}
	return (str);
}
