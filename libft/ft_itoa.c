/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:41:17 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/08 18:29:21 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa(char *str, long long nb, size_t i)
{
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		i--;
		nb /= 10;
	}
}

char		*ft_itoa(int n)
{
	size_t		i;
	long long	buf;
	char		*str;
	long long	nb;

	nb = (long long)n;
	i = (nb > 0 ? 0 : 1);
	buf = (nb > 0 ? nb : -nb);
	while (buf > 0)
	{
		buf = buf / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	itoa(str, nb, i);
	return (str);
}
