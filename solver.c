/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/27 18:29:56 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mapl		*increase(t_mapl *maps)
{
	int		size;
	t_mapl	*head;
	t_mapl	*sled;
	int		i;

	head = maps;
	size = maps->map_size + 1;
	while (maps)
	{
		i = -1;
		sled = maps->next;
		while (maps->map[++i])
			ft_strdel(&maps->map[i]);
		maps = sled;
	}
	maps = malloc(sizeof(t_mapl));
	maps = head;
	maps->prev = NULL;
	maps->map = create_map(size);
	maps->map_size = size;
	maps->pos_i = 0;
	maps->pos_j = 0;
	return (maps);
}

int			try_tet(t_fillit *list, t_mapl *maps, int i, int j)
{
	int n;
	int m;

	n = 0;
	while (n < list->height)
	{
		if (n + i >= maps->map_size)
			return (0);
		m = 0;
		while (m < list->width)
		{
			if (m + j >= maps->map_size || (list->tet[n][m]
			!= '.' && maps->map[n + i][m + j] != '.'))
				return (0);
			m++;
		}
		n++;
	}
	n = 0;
	while (n < list->height)
	{
		m = 0;
		while (m < list->width)
		{
			if ((list->tet[n][m] != '.' && maps->map[n + i][m + j] == '.'))
				maps->map[n + i][m + j] = list->tet[n][m];
			m++;
		}
		n++;
	}
	maps->next = malloc(sizeof(t_mapl));
	maps->next->map = maps->map;
	maps->next->prev = maps;
	maps->next->map_size = maps->map_size;
	maps->next->pos_i = 0;
	maps->next->pos_j = 0;
	return (1);
}

char		**create_map(int map_size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char**)ft_memalloc(sizeof(char *) * map_size + 1);
	while (i < map_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) * map_size + 1);
		ft_memset(map[i], '.', map_size);
		i++;
	}
	return (map);
}

int			starting_size(t_fillit *list)
{
	int			counter;
	t_fillit	*head;

	head = list;
	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	list = head;
	return (counter);
}

t_mapl		*solver(t_fillit *list, t_mapl *map,
		t_fillit *list_head, t_mapl *maps_head)
{
	int		i;
	int		j;
	int		x;

	if (list)
	{
		i = map->pos_i;
		while (i < map->map_size)
		{
			j = (i <= map->pos_i ? (map->pos_j) : 0);
			while (j < map->map_size)
			{
				if (try_tet(list, map, i, j))
				{
					map->pos_i = i;
					map->pos_j = j;
					return (solver(list->next,
							map->next, list_head, maps_head));
				}
				j++;
			}
			i++;
		}
		if (map->prev)
		{
			x = 0;
			while (map->prev->map[x])
			{
				ft_strset(map->prev->map[x], list->prev->c, '.');
				x++;
			}
			map->prev->pos_j++;
			return (solver(list->prev, map->prev, list_head, maps_head));
		}
		else
		{
			map = increase(maps_head);
			return (solver(list_head, map, list_head, maps_head));
		}
	}
	return (map);
}
