/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/27 18:28:12 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	t_mapl		*maps;
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
	maps = malloc(sizeof(t_mapl));
	maps->map_size = ft_sqrt(starting_size(list) * 4);
	maps->pos_i = 0;
	maps->pos_j = 0;
	maps->map = create_map(maps->map_size);
	maps = solver(list, maps, list, maps);
	write_grid(maps);
	free_map(maps);
	free_tet(list);
	close(fd);
	return (0);
}
