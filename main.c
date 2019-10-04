/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/04 20:24:19 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		write_grid(char **maps, t_fillit *list)
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

int			ft_validn(char *sss)
{
	int		i;
	char	str[547];
	int		fd;

	fd = open(sss, O_RDONLY);
	i = read(fd, str, 548);
	if (!((i + 2) % 21))
	{
		close(fd);
		write(1, "error\n", 6);
		exit(0);
	}
	close(fd);
	return (0);
}

int			main(int ac, char **av)
{
	int			fd;
	char		**map;
	t_fillit	*list;

	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1] + ft_validn(av[1]), O_RDONLY);
	if (!(list = read_grid(fd)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	list->map_size = ft_sqrt(starting_size(list) * 4);
	map = create_map(list->map_size);
	while (!(solver(list, map)))
		map = increase(map, list);
	write_grid(map, list);
	close(fd);
	return (0);
}
