/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:35 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/25 10:13:31 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main()
{
	int		fd;
	mapl	*maps;
	fillit	*list;

	fd = open("invalid_sample.fillit", O_RDONLY);
	list = read_grid(fd);
	maps->map_size = ft_sqrt(starting_size(list) * 4);
	maps->map = create_map(maps->map_size);
	maps = solver(list, maps);
	close(fd);
	return (0);
}
