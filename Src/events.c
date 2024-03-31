/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:27:45 by eliagarc          #+#    #+#             */
/*   Updated: 2024/01/01 19:13:50 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

int	close_button(t_window *wd)
{
	mlx_destroy_window(wd->mlx_ptr, wd->win_ptr);
	free_textures(wd, &wd->pc_txtes);
	free(wd->player);
	free_map(&wd->game_map);
	free(wd);
	ft_printf("\nGood bye!\n");
	exit(EXIT_SUCCESS);
}

int	close_window(t_window *wd)
{
	mlx_destroy_window(wd->mlx_ptr, wd->win_ptr);
	free_textures(wd, &wd->pc_txtes);
	free(wd->player);
	free_map(&wd->game_map);
	free(wd);
	wd = NULL;
	return (0);
}

int	key_event(int key, t_window *param)
{
	if (param->wdow == 0)
	{
		ft_printf("Key pressed: %d\t", key);
		if (!(key == RIGHT || key == RIGHT_D || key == LEFT \
		|| key == LEFT_A || key == DOWN || key == DOWN_S \
		|| key == UP || key == UP_W))
			ft_printf("\n");
		param->key = key;
		move_player(param);
		if (param->wdow == 0 && param->game_map->collectables == 0
			&& param->player->win == 0)
			print_gate(param, param->game_map->gate_x, \
			param->game_map->gate_y);
	}
	if (key == 53)
	{
		ft_printf("\nGood bye!\n");
		close_window(param);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	end_game(t_window **wd)
{
	ft_printf("\nYou win!\n");
	mlx_clear_window((*wd)->mlx_ptr, (*wd)->win_ptr);
	if ((*wd)->game_map->columns >= 10 && (*wd)->game_map->rows >= 7)
		mlx_put_image_to_window((*wd)->mlx_ptr, (*wd)->win_ptr, \
		(*wd)->pc_txtes->logo, ((*wd)->game_map->columns * 30 - 300) / 2, \
		((*wd)->game_map->rows * 30 - 200) / 2);
	(*wd)->wdow = 1;
	ft_printf("Press 'ESC' to quit game\n");
}
