/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:48:56 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/05 15:33:29 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_tet_next(t_fillit *start)
{
	int			i;
	t_fillit	*buf;

	while (start)
	{
		buf = start->next;
		i = -1;
		while (++i < start->height)
			ft_strdel(&start->tet[i]);
		free(start->tet);
		ft_strdel(&start->grid);
		free(start);
		start = buf;
	}
	start = NULL;
}

void		*free_error(t_fillit *list)
{
	t_fillit *sled;

	while (list)
	{
		sled = list->next;
		ft_strdel(&LG);
		free(list);
		list = sled;
	}
	list = NULL;
	return (0);
}

void		free_map(char **map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_strdel(&map[i]);
	free(map);
	map = NULL;
}
