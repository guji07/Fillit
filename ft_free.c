#include "fillit.h"

void	free_tet(t_fillit *list)
{
	t_fillit *sled;
	int i;

	while (list)
	{
		sled = list->next;
		i = 0;
		if (list->tet)
		{
			while (list->tet[i])
			{
				ft_strdel(&list->tet[i]);
				i++;
			}
		}
		if (list->grid)
			ft_strdel(&list->grid);
		free(list);
		list = NULL;
		list = sled;
	}
	list = NULL;
}

void	free_map(t_mapl *maps)
{
	int		i;
	t_mapl	*sled;
	t_mapl	*tmp;

	tmp = maps;
	while (maps)
	{
		i = 0;
		while (maps->map[i])
		{
			ft_strdel(&maps->map[i]);
			i++;
		}
		sled = maps->next;
		free(maps);
		maps = NULL;
		maps = sled;
	}
	free(maps);
	maps = tmp;
	while (maps->prev)
	{
		i = 0;
		while (maps->map[i])
		{
			ft_strdel(&maps->map[i]);
			i++;
		}
		sled = maps->prev;
		free(maps->prev);
		maps = NULL;
		maps = sled;
	}
	maps = NULL;
}
