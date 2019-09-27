/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:45:22 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/26 20:42:53 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

fillit *read_grid(int fd)
{
	fillit *list;
	char *line;
	int i;
	fillit *head;

	i = 0;
	list = init_grid();
	head = list;
	while (get_next_line(fd, &line) > 0)
	{
		while(*line)
		{
			list->grid[i] = *line;
			line++;
			i++;
		}
		if (i != 20)
			list->grid[i++] = '\n';
		else
		{
			CHECKRETURN(!(validate(list->grid, list)), NULL);
			list->next = init_grid();
			list->next->prev = list;
			list = list->next;
			i = 0;
		}
	}
	CHECKRETURN(!(validate(list->grid, list)), NULL);
	change_chars(head);
	return (head);
}

int		validate(char *str, fillit *list)
{
	int row;
	int symb;
	int dot;
	int fill;
	int col;

	col = 0;
	symb = 0;
	dot = 0;
	fill = 0;
	row = 0;
	while (str[symb])
	{
		if (str[symb] != '\n')
			row++;
		else if (str[symb] == '\n')
		{
			if (row != 4)
				return (0);
			row = 0;
			col++;
		}
		if (str[symb] == '.')
			dot++;
		else if (str[symb] == '#')
			fill++;
		symb++;
	}
	if (col != 4 || dot + fill != symb - 4 || dot != 12 || fill != 4 || !validate_piece(list))
		return (0);
	return (1);
}

int		validate_piece(fillit *list)
{
	int i;
	int height;
	int height2;
	int flag;

	flag = 0;
	height2 = 0;
	height = 0;
	i = 0;
	list->width = 0;
	while (list->grid[i])
	{
		if (list->grid[i] == '#')
		{
			if ((list->grid[i + 5] == '#' || list->grid[i] == '#') && list->grid[i - 5] != '#')
				list->width++;
			if (!(list->grid[i - 1] == '#' || list->grid[i + 1] == '#' || list->grid[i - 5] == '#' || list->grid[i + 5] == '#'))
				return (0);
			if (flag == 0)
			{
				flag = 1;
				height2 = i;
			}
			height = i;
		}
		i++;
	}
	list->height = height / 5 - height2 / 5 + 1;
	return (1);
}

void	change_chars(fillit *list)
{
	fillit *head;
	int i;

	head = list;
	while (list)
	{
		i = 0;
		list->tet = (char**)ft_memalloc(sizeof(char*) * list->height + 1);
		while (i < list->height)
		{
			list->tet[i] = (char*)ft_memalloc(sizeof(char) * 5);
			i++;
		}
		i = 0;
		while (*list->grid)
		{
			if (!(ft_strncmp(list->grid, "....\n", 4)))	
				list->grid += 5;
			else
			{
				ft_strncpy(list->tet[i], list->grid, 4);
				list->grid += 5;
				i++;
			}
		}
		list->tet = remove_dots(list->tet, list->height, list->width);
		list = list->next;
	}
	fill_chars(head);
	list = head;
}

void	fill_chars(fillit *list)
{
	int i;
	fillit *head;
	char c;

	head = list;
	c = 'A';
	while (list)
	{
		i = 0;
		while (list->tet[i])
		{
			ft_strset(list->tet[i], '#', c);
			i++;
		}
		list->c = c;
		c++;
		list = list->next;
	}
	list = head;
}

char	**remove_dots(char **tet, int height, int width)
{
	int i;
	int j;
	int k;
	char **tmp;

	i = 0;
	tmp = (char **)ft_memalloc(sizeof(char*) * height + 1);
	k = 0;
	j = 0;
	while (i < height)
	{
		tmp[i] = (char *)ft_memalloc(sizeof(char) * width + 1);
		i++;
	}
	i = 0;
	while (tet[i][j])
	{
		if (tet[i][j] == '.' && tet[i + (2 <= height ? 1 : 0)][j] == '.' && tet[i + (3 <= height ? 2 : 0)][j] == '.' && tet[i + (4 <= height ? 3 : 0)][j] == '.')
			j++;
		else
		{
			tmp[i][k] = tet[i][j];
			tmp[i + (2 <= height ? 1 : 0)][k] = tet[i + (2 <= height ? 1 : 0)][j];
			tmp[i + (3 <= height ? 2 : 0)][k] = tet[i + (3 <= height ? 2 : 0)][j];
			tmp[i + (4 <= height ? 3 : 0)][k] = tet[i + (4 <= height ? 3 : 0)][j];
			k++;
			j++;
		}
	}
	return (tmp);
}

void	write_grid(fillit *list, mapl *maps)
{
	int i;

	i = 0;
	/*while (list->tet[i])
	{
		printf("%s\n", list->tet[i]);
		i++;
	}*/
	//printf("\nHeight [%d]\n", list->height);
	//printf("Width [%d]\n\n", list->width);
	i = 0;
	while (maps->map[i])
	{
		ft_putendl(maps->map[i]);
		i++;
	}
	ft_putchar('\n');
	printf("\ni [%d]\n", maps->pos_i);
	printf("j [%d]\n\n", maps->pos_j);
}