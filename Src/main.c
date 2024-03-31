/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:10:21 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/30 15:20:19 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static void	game_update_aux2(t_window *wd, int *pac_status)
{
	if (wd->pc_txtes->view == UP)
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, \
		wd->player->y * 30 + 3, wd->player->x * 30 + 3);
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->pac_man[2][*pac_status], \
		wd->player->y * 30, wd->player->x * 30);
	}
	else if (wd->pc_txtes->view == DOWN)
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, \
		wd->player->y * 30 + 3, wd->player->x * 30 + 3);
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->pac_man[3][*pac_status], \
		wd->player->y * 30, wd->player->x * 30);
	}
}

static void	game_update_aux(t_window *wd, int *pac_status)
{
	if (wd->pc_txtes->view == RIGHT)
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, wd->player->y * 30 + 3, \
		wd->player->x * 30 + 3);
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->pac_man[0][*pac_status], \
		wd->player->y * 30, wd->player->x * 30);
	}
	else if (wd->pc_txtes->view == LEFT)
	{
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->black, wd->player->y * 30 + 3, \
		wd->player->x * 30 + 3);
		mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
		wd->pc_txtes->pac_man[1][*pac_status], wd->player->y * 30, \
		wd->player->x * 30);
	}
	game_update_aux2(wd, pac_status);
}

static void	put_sprite(t_window *wd)
{
	mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
	wd->pc_txtes->black, wd->player->y * 30 + 3, \
	wd->player->x * 30 + 3);
	mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, \
	wd->pc_txtes->closed, wd->player->y * 30, \
	wd->player->x * 30);
	if (wd->pc_txtes->status == 17)
		wd->pc_txtes->status = 0;
}

int	game_update(t_window *wd)
{
	int	pac_status;

	pac_status = 0;
	if (wd->wdow == 0 && wd->player)
	{
		wd->pc_txtes->status++;
		if (wd->pc_txtes->status < 6)
			pac_status = 0;
		else if (wd->pc_txtes->status >= 6
			&& wd->pc_txtes->status < 12)
			pac_status = 1;
		if (wd->pc_txtes->status >= 12
			&& wd->pc_txtes->status < 18)
			put_sprite(wd);
		else
			game_update_aux(wd, &pac_status);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_window	*map_window;

	if (argc == 2)
	{
		if (init_window(argv[1], &map_window) == -1)
			return (1);
		init_map(map_window);
		mlx_do_key_autorepeaton(map_window->mlx_ptr);
		mlx_loop_hook(map_window->mlx_ptr, &game_update, map_window);
		loop_game(map_window->win_ptr, map_window->mlx_ptr, \
		map_window, key_event);
	}
	else if (argc > 2)
		return (ft_printf("Too many maps!\n"), 0);
	else
		return (ft_printf("Map required!\n"), 0);
	return (0);
}
