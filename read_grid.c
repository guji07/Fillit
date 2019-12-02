/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:45:22 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/04 22:51:57 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*read_grid(int fd)
{
	t_fillit	*list;
	char		*line;
	int			i;
	t_fillit	*head;
	char		*tmp;

	i = 0;
	list = init_grid();
	head = list;
	while (get_next_line(fd, &line) > 0 && (tmp = line))
	{
		while (*line)
			LG[i++] = *(line++);
		if (i < 20 + ft_strfdel(&tmp))
			LG[i++] = '\n';
		else
		{
			CHECKRETURN(!(validate(LG, list)), free_error(head));
			list->next = init_grid();
			list = list->next;
			i = 0;
		}
	}
	CHECKRETURN(!(validate(LG, list)), free_error(head));
	return (head + change_chars(head));
}

int			count_ne(char *str)
{
	int i;
	int count;
	int fill;

	i = -1;
	fill = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			fill++;
			if (str[i + 1] == '#')
				count++;
			if (str[i - 1] == '#')
				count++;
			if (str[i - 5] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
		}
		if (fill == 4 && count < 6)
			return (0);
	}
	return (1);
}

int			validate(char *str, t_fillit *list)
{
	t_val val;

	val.col = 0;
	val.s = -1;
	val.dot = 0;
	val.fill = 0;
	val.row = 0;
	while (str[++val.s])
	{
		if (str[val.s] != '\n')
			val.row++;
		else if (str[val.s] == '\n')
		{
			if (val.row != 4)
				return (0);
			val.row = 0;
			val.col++;
		}
		if (str[val.s] == '.')
			val.dot++;
		else if (str[val.s] == '#')
			val.fill++;
	}
	return (!(val.col != 4 || val.dot + val.fill != val.s - 4 || val.dot != 12
	|| val.fill != 4 || !validate_piece(list) || !(count_ne(str))));
}

int			validate_piece(t_fillit *list)
{
	int i;
	int height;
	int flag;

	flag = 0;
	height = 0;
	i = -1;
	list->width = 0;
	while (LG[++i])
	{
		if (LG[i] == '#')
		{
			if ((LG[i + 5] == '#' || LG[i] == '#') && LG[i - 5] != '#')
				++list->width;
			CHECKRETURN((!(LG[i - 1] == '#' || LG[i + 1] == '#' ||
			LG[i - 5] == '#' || LG[i + 5] == '#')), 0);
			if (flag == 0)
			{
				flag = 1;
				height = i;
			}
			list->height = i / 5 - height / 5 + 1;
		}
	}
	return (1);
}

int			fill_chars(t_fillit *list)
{
	int			i;
	t_fillit	*head;
	char		c;

	head = list;
	c = 'A';
	while (list)
	{
		i = 0;
		while (i < list->height)
		{
			ft_strset(list->tet[i], '#', c);
			i++;
		}
		list->c = c;
		c++;
		list = list->next;
	}
	list = head;
	return (0);
}
