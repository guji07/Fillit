/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/03 15:08:02 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_grid(char **maps, t_fillit *list)
{
	int i;

	i = 0;
	while (i < list->map_size)
	{
		ft_putendl(maps[i]);
		i++;
	}
	free_map(maps, list->map_size);
	free_tet_next(list);
}

int		main(int ac, char **av)
{
	int			fd;
	char		**map;
	t_fillit	*list;

	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!(list = read_grid(fd)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	list->map_size = ft_sqrt(starting_size(list) * 4);
	map = create_map(list->map_size);
	while (!(solver(list, map)))
	{
		free_map(map, list->map_size);
		map = increase(map, list);
	}
	write_grid(map, list);
	close(fd);
	return (0);
}
