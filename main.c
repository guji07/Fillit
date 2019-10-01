/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/01 18:42:10 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	**map;
	t_fillit	*list;

	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	list = read_grid(fd);
	if (list == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	list->map_size = ft_sqrt(starting_size(list) * 4);
	list->pos_i = 0;
	list->pos_j = 0;
	map = create_map(list->map_size);
	while (solver(list, map) == 0)
	{
		free_map(map, list->map_size);
		map = increase(map, list);
	}
	write_grid(map, list);
	close(fd);
	return (0);
}
