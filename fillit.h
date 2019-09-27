/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:50 by cauranus          #+#    #+#             */
/*   Updated: 2019/09/27 18:27:09 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

typedef struct		s_lists
{
	char			*grid;
	char			**tet;
	int				height;
	int				width;
	char			c;
	struct s_lists	*next;
	struct s_lists	*prev;
}					t_fillit;

typedef struct		s_mapl
{
	char			**map;
	int				map_size;
	int				pos_i;
	int				pos_j;
	struct s_mapl	*next;
	struct s_mapl	*prev;
}					t_mapl;

int					validate_piece(t_fillit *list);
int					validate(char *str, t_fillit *list);
void				write_grid(t_mapl *maps);
t_fillit			*read_grid(int fd);
t_fillit			*init_grid(void);
int					change_chars(t_fillit *list);
int					fill_chars(t_fillit *list);
char				**remove_dots(char **tet, int high, int width);
char				**create_map(int map_size);
int					starting_size(t_fillit *list);
t_mapl				*solver(t_fillit *list,
		t_mapl *map, t_fillit *list_head, t_mapl *maps_head);
int					valid_tet(char **map, char c);
int					try_tet(t_fillit *list, t_mapl *maps, int i, int j);
void				free_tet(t_fillit *list);
void				free_map(t_mapl *maps);

#endif
