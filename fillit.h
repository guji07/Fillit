/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:50 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/30 16:51:17 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef t_fillit_H
# define t_fillit_H
# include "./libft/libft.h"

typedef struct		g_list
{
	char			*grid;
	char			**tet;
	int				height;
	int				width;
	char			c;
	struct	g_list	*next;
	struct	g_list	*prev;
}					t_fillit;

typedef struct		map_l
{
	char **map;
	int				map_size;
	int				pos_i;
	int				pos_j;
	struct	map_l	*next;
	struct	map_l	*prev;
}					t_mapl;

int					validate_piece(t_fillit *list);
int 				validate(char *str, t_fillit *list);
void				write_grid(t_mapl *maps, t_fillit *list);
t_fillit				*read_grid(int fd);
t_fillit				*init_grid(void);
void				change_chars(t_fillit *list);
void				fill_chars(t_fillit *list);
char				**remove_dots(char **tet, int height, int width);
char				**create_map(int map_size);
int					starting_size(t_fillit *list);
int					solver(t_fillit *list, t_mapl *map);
int					valid_tet(char **map, char c);
int					try_tet(t_fillit *list, t_mapl *maps, int i, int j);
int					free_error(t_fillit *list);
void				free_tet_back(t_fillit *list);
void				free_map_back(t_mapl *map);
void				mapcpy(t_mapl *maps);
void				free_map_next(t_mapl *map);
void				write_test(t_mapl *maps, t_fillit *list);
t_mapl 				*increase(t_mapl *maps);
#endif