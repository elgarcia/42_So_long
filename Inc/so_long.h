/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:10:33 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/30 14:30:43 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../lib/Libft/libft.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
# define RIGHT_D 2
# define RIGHT 124
# define LEFT_A 0
# define LEFT 123
# define DOWN_S 1
# define DOWN 125
# define UP_W 13
# define UP 126

typedef struct s_node
{
	int				x;
	int				y;
	char			valor;
	struct s_node	*next;
}					t_node;

typedef struct s_map
{
	int		columns;
	int		rows;
	int		collectables;
	int		players;
	int		gate;
	int		gate_x;
	int		gate_y;
	char	**map;
	t_node	*route;
	int		count;
	int		gate_accessible;
	int		valid_map;
}			t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	win;
}		t_player;

typedef struct s_textures
{
	int		status;
	int		view;
	void	*pac_man[4][2];
	void	*closed;
	void	*wall;
	void	*black;
	void	*gate;
	void	*collectable;
	void	*logo;
}			t_textures;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	*pc_txtes;
	int			moves;
	int			key;
	t_player	*player;
	t_map		*game_map;
	int			wdow;
}				t_window;

/* AUXILIAR FUNCTIONS */
void	ft_free(char **item, int size);
int		is_saved(t_node *list, int x, int y);
void	ft_nodeadd_back(t_node **lst, t_node *new);
void	ft_free_node(t_node *lst);
void	free_route(t_node *route);
void	free_map(t_map **map);
void	free_textures(t_window *wd, t_textures **txt);

/* EVENT FUNCTIONS */
int		key_event(int key, t_window *param);
void	loop_game(void *win_ptr, void *mlx_ptr, t_window *wd, \
int (*f)(int, t_window *));

/* WINDOW FUNCTIONS	*/
int		close_window(t_window *param);
int		close_button(t_window *wd);

/* INIT FUNCTIONS */
int		init_window(char *argv, t_window **map_window);
void	init_map(t_window *wd);
void	init_textures(t_window *wd);
t_node	*init_node(t_map *map, int x, int y);

/* GAME FUNCTIONS */
void	move_player(t_window *wd);
int		game_update(t_window *wd);
void	print_map(t_window *wd);
void	print_player(t_window *wd, int x, int y);
void	save_gate(t_window *wd, int x, int y);
void	print_gate(t_window *wd, int x, int y);
void	print_walls(t_window *wd, int x, int y);
void	print_collectables(t_window *wd, int x, int y);
void	end_game(t_window **wd);
void	is_accessible(t_map *map, int x, int y);

/* MAP FUNCTIONS */
int		read_map(char *map_file, t_window *map);
int		assign_map(int *fd, char *map_file, t_map *map);
int		check_dimensions(t_map *map);
int		check_map(t_window *map);
int		check_chars(t_window *map, int i, int j);
int		check_borders(t_map *map, int i, int j);

#endif
