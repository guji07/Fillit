/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/01 20:38:35 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
char	**increase(char **maps, t_fillit *list)
{
	static int i = 0;

	i++;
	free_map(maps, list->map_size);
	list->map_size++;
	list->pos_i = 0;
	list->pos_j = 0;
	return (create_map(list->map_size));
}

int		try_tet(t_fillit *list, char **maps, int i, int j)
{
	int n;
	int m;

	n = -1;
	while (++n < list->height)
	{
		if (n + i >= list->map_size)
			return (0);
		m = -1;
		while (++m < list->width)
		{
			if (m + j >= list->map_size || (list->tet[n][m] != '.' && maps[n + i][m + j] != '.'))
				return(0);
		}
	}
	n = -1;
	while (++n < list->height)
	{
		m = -1;
		while (++m < list->width)
			if ((list->tet[n][m] != '.' && maps[n + i][m + j] == '.'))
				maps[n + i][m + j] = list->tet[n][m];
	}
	if (list->next)
	{
		list->next->map_size = list->map_size;
		list->next->pos_i = 0;
		list->next->pos_j = 0;
	}
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

int	solver(t_fillit *list, char **map)
{
	int		i;
	int		j;
	int 	x;

	if (list)
	{
		i = list->pos_i;
		while (i < list->map_size)
		{
			j = (i == list->pos_i ? (list->pos_j) : 0);
			while (j < list->map_size)
			{
				if(try_tet(list, map, i, j))
				{
					list->pos_i = i;
					list->pos_j = j;
					return (solver(list->next, map));
				}
				j++;
			}
			i++;
		}
		if (list->prev)
		{
			x = -1;
			while (++x < list->map_size)
				ft_strset(map[x], list->prev->c, '.');
			list->prev->pos_j++;
			return (solver(list->prev, map));
		}
		else
			return (0);
	}
	return (1);
}
/*
void write_test(char **maps, t_fillit *list)
{
	int i = -1;
	static int j = 0;

	j++;
	if (j > 3775860)
	{	printf("\n%i\n", j);
		while (++i < list->map_size)
			ft_putendl(maps[i]);
	}
}*/