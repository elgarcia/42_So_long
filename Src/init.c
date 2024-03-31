/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:11:22 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/30 16:26:55 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	init_textures2(t_window *wd, int wd_width, int wd_height)
{
	wd->pc_txtes->closed = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_closed.xpm", &wd_width, &wd_height);
	wd->pc_txtes->wall = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Other/Walls/wall.xpm", &wd_width, &wd_height);
	wd->pc_txtes->black = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Other/black_space.xpm", &wd_width, &wd_height);
	wd->pc_txtes->gate = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Other/Portal/star.xpm", &wd_width, &wd_height);
	wd->pc_txtes->collectable = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Other/Pacdots/pacdot_food.xpm", &wd_width, &wd_height);
	wd->pc_txtes->logo = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Other/Logo/winner.xpm", &wd_width, &wd_height);
	if (!wd->pc_txtes->closed || !wd->pc_txtes->wall || \
	!wd->pc_txtes->black || !wd->pc_txtes->gate || \
	!wd->pc_txtes->collectable || !wd->pc_txtes->logo)
		return (ft_printf("Invalid textures!\n"), exit(0));
}

void	init_textures(t_window *wd)
{
	int	wd_width;
	int	wd_height;

	wd->pc_txtes->pac_man[0][0] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_open_right.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[0][1] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_semi_right.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[1][0] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_open_left.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[1][1] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_semi_left.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[2][0] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_open_up.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[2][1] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_semi_up.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[3][0] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_open_down.xpm", &wd_width, &wd_height);
	wd->pc_txtes->pac_man[3][1] = mlx_xpm_file_to_image(wd->mlx_ptr, \
	"textures/Pac-Man/pac_semi_down.xpm", &wd_width, &wd_height);
	if (!wd->pc_txtes->pac_man[0][0] || !wd->pc_txtes->pac_man[0][1] || \
	!wd->pc_txtes->pac_man[1][0] || !wd->pc_txtes->pac_man[1][1] || \
	!wd->pc_txtes->pac_man[2][0] || !wd->pc_txtes->pac_man[2][1] || \
	!wd->pc_txtes->pac_man[3][0] || !wd->pc_txtes->pac_man[3][1])
		return (ft_printf("Invalid textures!\n"), exit(0));
	init_textures2(wd, wd_width, wd_height);
}

t_node	*init_node(t_map *map, int x, int y)
{
	t_node	*aux;

	aux = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!aux)
		return (NULL);
	aux->x = x;
	aux->y = y;
	aux->valor = map->map[x][y];
	aux->next = NULL;
	return (aux);
}

void	print_map(t_window *wd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < wd->game_map->rows)
	{
		while (j < wd->game_map->columns)
		{
			print_player(wd, i, j);
			save_gate(wd, i, j);
			print_walls(wd, i, j);
			print_collectables(wd, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_map(t_window *wd)
{
	if (wd->moves == 0)
	{
		wd->pc_txtes = (t_textures *)ft_calloc(1, sizeof(t_textures));
		wd->pc_txtes->status = 0;
		wd->pc_txtes->view = RIGHT;
		init_textures(wd);
		print_map(wd);
	}
}
