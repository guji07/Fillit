/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/01 16:04:34 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mapl 	*increase(t_mapl *maps)
{
	int size;
	t_mapl *head;
	t_mapl *sled;
	int i;
	
	head = maps;
	size = maps->map_size + 1;
	while (maps)
	{
		i = -1;
		sled = maps->next;
		if (maps->map)
		{
			while (++i < maps->map_size)
				ft_strdel(&maps->map[i]);
			free(maps->map);
		}
		free(maps);
		maps = sled;
	}
	maps = malloc(sizeof(t_mapl));
	maps = head;
	maps->prev = NULL;
	maps->next = NULL;
	maps->map = create_map(size);
	maps->map_size = size;
	maps->pos_i = 0;
	maps->pos_j = 0;
	return (maps);
}

int		try_tet(t_fillit *list, t_mapl *maps, int i, int j)
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
			if (m + j >= maps->map_size || (list->tet[n][m] != '.' && maps->map[n + i][m + j] != '.'))
				return(0);
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
	if (!(maps->next = malloc(sizeof(t_mapl))))
		return (0);
	maps->next->next = NULL;
	maps->next->map = maps->map;
	maps->next->prev = maps;
	maps->next->map_size = maps->map_size;
	maps->next->pos_i = 0;
	maps->next->pos_j = 0;
	return (1);
}

char	**create_map(int map_size)
{
	int i;
	char **map;


	i = 0;
	map = (char**)malloc(sizeof(char *) * map_size);
	while (i < map_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) * map_size + 1);
		ft_memset(map[i], '.', map_size);
		i++;
	}
	return (map);
}

int		starting_size(t_fillit *list)
{
	int	counter;
	t_fillit *head;
	
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

int			solver(t_fillit *list, t_mapl *map)
{
	int 	i;
	int 	j;

	if (list)
	{
		for (i = map->pos_i; i < map->map_size; i++)
		{
			j = (i <= map->pos_i ? (map->pos_j) : 0);
			while (j < map->map_size)
			{
				if (try_tet(list, map, i, j))
				{
					map->pos_i = i;
					map->pos_j = j;
					return (solver(list->next, map->next));
				}
				j++;
			}
		}
		map = map->prev;
		if (list->prev)
		{
			for (i = 0; i < (map->map_size); ++i)
			{
				ft_strset(map->map[i], list->prev->c, '.');}
			list = list->prev;
			free(map->next);
			map->next = NULL;
			map->pos_j++;
			return (solver(list, map));
		}
		else
			return (0);
	}
	return (1);
}
