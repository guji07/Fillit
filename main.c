/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/26 16:18:30 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main()
{
	int		fd;
	mapl	*maps;
	fillit	*list;

	fd = open("valid_sample.fillit", O_RDONLY);
	list = read_grid(fd);
	maps = malloc(sizeof(mapl));
	maps->map_size = ft_sqrt(starting_size(list) * 4);
	maps->pos_i = 0;
	maps->pos_j = 0;
	maps->map = create_map(maps->map_size);
	maps = solver(list, maps, list, maps);
	//write_grid(list, maps);
	close(fd);
	return (0);
}
