/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:48:56 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/01 20:02:07 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_tet_next(t_fillit *start)
{
	int i;
	t_fillit *buf;
	
	while (start)
	{
		buf = start->next;
		i = -1;
		while (++i < start->height - 1)
			ft_strdel(&start->tet[i]);
		free(start->tet);
		ft_strdel(&start->grid);
		free(start);
		start = buf;
	}
	start = NULL;
}

void	free_tet_back(t_fillit *list)
{
	t_fillit	*start;
	t_fillit	*buf;
	int		i;

	start = list;
	list = (list->prev ? list->prev : list);
	while (list->prev)
	{
		buf = list;
		list = list->prev;
		i = -1;
		while (++i < list->height)
			ft_strdel(&list->tet[i]);
		free(list->tet);
		ft_strdel(&list->grid);
		free(buf);
	}
	list = start;
	free_tet_next(list);
}

int		free_error(t_fillit *list)
{
	t_fillit *sled;

	while (list)
	{
		sled = list;
		list = list->next;
		ft_strdel(&list->grid);
		free(sled);
	}
	list = NULL;
	return (1);
}

/*void	free_map_back(t_mapl *map)
{
	t_mapl	*start;
	t_mapl	*buf;
	int		i;

	start = map;
	if (map->map)
	{
		i = -1;
		while (++i < map->map_size)
			ft_strdel(&map->map[i]);
		free(map->map);
	}
	map = (map->prev ? map->prev : map);
	while (map->prev)
	{
		buf = map->prev;
		free(map);
		map = buf;
	}
	map = start;
	while (map)
	{
		buf = map->next;
		free(map);
		map = buf;
	}
	map = NULL;
}
*/
void	free_map(char **map, int size)
{
	int i;
	
	i = -1;
	while (++i < size)
		ft_strdel(&map[i]);
	//free(map);
	map = NULL;
}
