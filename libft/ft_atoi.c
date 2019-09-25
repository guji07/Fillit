/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:34:08 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/11 23:11:50 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					neg;

	neg = 0;
	num = 0;
	while ((*str == '\n') || (*str == ' ') || (*str == '\f')
	|| (*str == '\r') || (*str == '\t') || (*str == '\v'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num * 1000 < num)
			return (neg ? 0 : -1);
		str++;
	}
	return (neg ? (-1 * (int)num) : (int)num);
}
