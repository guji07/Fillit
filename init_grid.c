/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:34:58 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/23 14:23:11 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

fillit *init_grid(void)
{
	fillit *ret;

	ret = malloc(sizeof(fillit));
	ret->grid = (char *)ft_memalloc(sizeof(char *) * 21);
	ret->next = NULL;
	if (!ret)
		return (NULL);
	return (ret);
}