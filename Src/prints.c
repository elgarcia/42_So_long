/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:42 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/28 19:54:00 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	print_player(t_window *wd, int x, int y)
{
	if (wd->game_map->map[x][y] == 'P' && wd->moves == 0)
	{
		wd->player->x = x;
		wd->player->y = y;
	}
}

void	print_gate(t_window *wd, int x, int y)
{
	mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
	wd->pc_txtes->gate, y * 30, x * 30);
}

void	save_gate(t_window *wd, int x, int y)
{
	if (wd->game_map->map[x][y] == 'E')
	{
		wd->game_map->gate_x = x;
		wd->game_map->gate_y = y;
	}
}

void	print_walls(t_window *wd, int x, int y)
{
	if (wd->game_map->map[x][y] == '1')
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->wall, y * 30, x * 30);
}

void	print_collectables(t_window *wd, int x, int y)
{
	if (wd->game_map->map[x][y] == 'C')
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->collectable, y * 30, x * 30);
}
