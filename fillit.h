/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauranus <cauranus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:33:50 by cauranus          #+#    #+#             */
/*   Updated: 2019/10/01 17:35:22 by cauranus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FILLIT_H
# define T_FILLIT_H
# include "./libft/libft.h"

typedef struct		g_list
{
	char			*grid;
	char			**tet;
	int				height;
	int				width;
	char			c;
	int				pos_i;
	int				pos_j;
	int				map_size;
	struct	g_list	*next;
	struct	g_list	*prev;
}					t_fillit;

int					validate_piece(t_fillit *list);
int 				validate(char *str, t_fillit *list);
void				write_grid(char **maps, t_fillit *list);
t_fillit			*read_grid(int fd);
t_fillit			*init_grid(void);
void				change_chars(t_fillit *list);
void				fill_chars(t_fillit *list);
char				**remove_dots(char **tet, int height, int width);
char				**create_map(int map_size);
int					starting_size(t_fillit *list);
int					solver(t_fillit *list, char **map);
int					valid_tet(char **map, char c);
int					try_tet(t_fillit *list, char **maps, int i, int j);
int					free_error(t_fillit *list);
void				free_tet_back(t_fillit *list);
void				write_test(char **maps, t_fillit *list);
void				free_map(char **map, int size);
char				**increase(char **maps, t_fillit *list);

#endif
