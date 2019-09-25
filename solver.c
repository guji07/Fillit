/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:46:40 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/25 10:21:23 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
char	**create_map(int map_size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char**)ft_memalloc(sizeof(char *) * map_size + 1);
	while (i < map_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) * map_size + 1);
		i++;
	}
	return (map);
}

int		starting_size(fillit *list)
{
	int		counter;
	fillit	*head;

	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	list = head;
	return (counter);
}

mapl	*nextmap(mapl *map)
{
	
}
mapl	*solver(fillit *list, mapl *map, fillit *list_head, mapl *maps_head)
{
	int		i;
	int		j;
	int		n;

	if (list)
	{
		i = -1;
		while (++i < map->map_size)
		{
			j = -1;
			while (++j < map->map_size)
			{
				if (ft_trytet(list, map, i, j))
					return (solver(list->next, map->next));
			}
		}
		return (solver(list_head, increase(maps_head)));
	}
	return (map);
}


void	try_tet(fillit *list)
{
	
}


