/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/02 17:03:09 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**increase(char **maps, t_fillit *list)
{
	free_map(maps, list->map_size);
	list->map_size++;
	return (create_map(list->map_size));
}

int		try_tet(t_fillit *list, char **maps, int i, int j)
{
	int n;
	int m;

	n = -1;
	while (++n < list->height)
	{
		m = -1;
		while (++m < list->width)
			CHECKRETURN((list->tet[n][m] != '.'
			&& maps[n + i][m + j] != '.'), 0);
	}
	n = -1;
	while (++n < list->height)
	{
		m = -1;
		while (++m < list->width)
		{
			if ((list->tet[n][m] != '.' && maps[n + i][m + j] == '.'))
				maps[n + i][m + j] = list->tet[n][m];
		}
	}
	if (list->next)
		list->next->map_size = list->map_size;
	return (1);
}

char	**create_map(int map_size)
{
	int		i;
	char	**map;

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

int		solver(t_fillit *list, char **map)
{
	int	i;
	int	j;
	int	x;

	CHECKRETURN((!list), 1);
	i = -1;
	while (++i <= list->map_size - list->height)
	{
		j = -1;
		while (++j <= list->map_size - list->width)
		{
			if (try_tet(list, map, i, j))
				if (solver(list->next, map))
					return (1);
				else
				{
					x = -1;
					while (++x < list->map_size)
						ft_strset(map[x], list->c, '.');
				}
		}
	}
	return (0);
}
