/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:34:58 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/02 21:21:10 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*init_grid(void)
{
	t_fillit *ret;

	ret = malloc(sizeof(t_fillit));
	ret->grid = (char *)ft_memalloc(sizeof(char *) * 21);
	ret->next = NULL;
	return (ret);
}

char		**remove_dots(char **tet, int h, int width)
{
	int		i;
	int		j;
	int		k;
	char	**tm;

	i = -1;
	tm = (char **)malloc(sizeof(char*) * h);
	k = 0;
	j = 0;
	while (++i < h)
		tm[i] = (char *)ft_memalloc(sizeof(char) * width + 1);
	while (tet[0][j])
	{
		if (tet[0][j] == '.' && tet[0 + (2 <= h ? 1 : 0)][j] == '.' &&
		tet[(3 <= h ? 2 : 0)][j] == '.' && tet[(4 <= h ? 3 : 0)][j] == '.')
			j++;
		else
		{
			tm[0][k] = tet[0][j];
			tm[(2 <= h ? 1 : 0)][k] = tet[(2 <= h ? 1 : 0)][j];
			tm[(3 <= h ? 2 : 0)][k] = tet[(3 <= h ? 2 : 0)][j];
			tm[(4 <= h ? 3 : 0)][k++] = tet[(4 <= h ? 3 : 0)][j++];
		}
	}
	return (tm);
}

void		ft_iamgenius(int *i, char **tm, char **ya_eblan)
{
	*i = 0;
	*tm = *ya_eblan;
	*ya_eblan = *ya_eblan - 5;
}

int			ft_iamsmart(int *i)
{
	return ((*i = -1) + 1);
}

void		change_chars(t_fillit *list)
{
	t_fillit	*head;
	int			i;
	char		*tm;
	char		**temp;

	head = list;
	while (list)
	{
		i = -1;
		list->tet = (char**)malloc(sizeof(char*) * list->height);
		while (++i < list->height)
			list->tet[i] = (char*)ft_memalloc(sizeof(char) * 5);
		ft_iamgenius(&i, &tm, &LG);
		while (*(LG += 5))
			if ((ft_strncmp(LG, "....\n", 4)))
				ft_strncpy(list->tet[i++], LG, 4);
		LG = tm + ft_iamsmart(&i);
		temp = remove_dots(list->tet, list->height, list->width);
		while (++i < list->height)
			ft_strdel(&list->tet[i]);
		free(list->tet);
		list->tet = temp;
		list = list->next;
	}
	fill_chars(head);
}
