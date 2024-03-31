/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:27:49 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/29 15:36:45 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	right_movement(t_window *wd, int x, int y)
{
	if (y <= wd->game_map->columns && wd->game_map->map[x][y] != '1')
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, (y - 1) * 30 + 3, x * 30 + 3);
		if (wd->game_map->map[x][y] == 'C')
		{
			wd->game_map->map[x][y] = '0';
			wd->game_map->collectables--;
		}
		if (wd->game_map->map[x][y] == 'E' && wd->game_map->collectables == 0)
			end_game(&wd);
		else
		{
			wd->player->y++;
			wd->pc_txtes->view = RIGHT;
			mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
			wd->pc_txtes->pac_man[0][0], y * 30, x * 30);
			ft_printf("Moves: %d\tCollectables left: %d\n", \
			++(wd->moves), wd->game_map->collectables);
		}
	}
	else
		ft_printf("Moves: %d\n", wd->moves);
}

static void	left_movement(t_window *wd, int x, int y)
{
	if (y >= 0 && wd->game_map->map[x][y] != '1')
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, (y + 1) * 30 + 3, x * 30 + 3);
		if (wd->game_map->map[x][y] == 'C')
		{
			wd->game_map->map[x][y] = '0';
			wd->game_map->collectables--;
		}
		if (wd->game_map->map[x][y] == 'E' && wd->game_map->collectables == 0)
			end_game(&wd);
		else
		{
			wd->player->y--;
			wd->pc_txtes->view = LEFT;
			mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
			wd->pc_txtes->pac_man[1][0], y * 30, x * 30);
			ft_printf("Moves: %d\tCollectables left: %d\n", \
			++(wd->moves), wd->game_map->collectables);
		}
	}
	else
		ft_printf("Moves: %d\n", wd->moves);
}

static void	up_movement(t_window *wd, int x, int y)
{
	if (x >= 0 && wd->game_map->map[x][y] != '1')
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, y * 30 + 3, (x + 1) * 30 + 3);
		if (wd->game_map->map[x][y] == 'C')
		{
			wd->game_map->map[x][y] = '0';
			wd->game_map->collectables--;
		}
		if (wd->game_map->map[x][y] == 'E' && wd->game_map->collectables == 0)
			end_game(&wd);
		else
		{
			wd->player->x--;
			wd->pc_txtes->view = UP;
			mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
			wd->pc_txtes->pac_man[2][0], y * 30, x * 30);
			ft_printf("Moves: %d\tCollectables left: %d\n", \
			++(wd->moves), wd->game_map->collectables);
		}
	}
	else
		ft_printf("Moves: %d\n", wd->moves);
}

static void	down_movement(t_window *wd, int x, int y)
{
	if (x <= wd->game_map->rows && wd->game_map->map[x][y] != '1')
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, y * 30 + 3, (x - 1) * 30 + 3);
		if (wd->game_map->map[x][y] == 'C')
		{
			wd->game_map->map[x][y] = '0';
			wd->game_map->collectables--;
		}
		if (wd->game_map->map[x][y] == 'E' && wd->game_map->collectables == 0)
			end_game(&wd);
		else
		{
			wd->player->x++;
			wd->pc_txtes->view = DOWN;
			mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
			wd->pc_txtes->pac_man[3][0], y * 30, x * 30);
			ft_printf("Moves: %d\tCollectables left: %d\n", \
			++(wd->moves), wd->game_map->collectables);
		}
	}
	else
		ft_printf("Moves: %d\n", wd->moves);
}

void	move_player(t_window *wd)
{
	if (wd->key == RIGHT_D || wd->key == RIGHT)
		right_movement(wd, wd->player->x, wd->player->y + 1);
	else if (wd->key == LEFT_A || wd->key == LEFT)
		left_movement(wd, wd->player->x, wd->player->y - 1);
	else if (wd->key == DOWN_S || wd->key == DOWN)
		down_movement(wd, wd->player->x + 1, wd->player->y);
	else if (wd->key == UP_W || wd->key == UP)
		up_movement(wd, wd->player->x - 1, wd->player->y);
}
