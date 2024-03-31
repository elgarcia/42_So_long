/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:54:38 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/29 22:34:26 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

int	check_chars(t_window *map, int i, int j)
{
	if (map->game_map->map[i][j] != 'C' && map->game_map->map[i][j] != 'P'
		&& map->game_map->map[i][j] != 'E' && map->game_map->map[i][j] != '1'
		&& map->game_map->map[i][j] != '0')
		return (-1);
	if (map->game_map->map[i][j] == 'C')
		map->game_map->collectables++;
	if (map->game_map->map[i][j] == 'P')
	{
		map->game_map->players++;
		if (map->game_map->players >= 2)
			return (-1);
		map->player->x = i;
		map->player->y = j;
	}
	if (map->game_map->map[i][j] == 'E')
		map->game_map->gate++;
	return (0);
}

int	check_borders(t_map *map, int i, int j)
{
	if (i == 0 || i == (map->rows - 1))
	{
		if (map->map[i][j] != '1')
			return (-1);
	}
	if (j == 0 || j == (map->columns - 1))
	{
		if (map->map[i][j] != '1')
			return (-1);
	}
	return (0);
}

int	is_saved(t_node *list, int x, int y)
{
	t_node	*aux;

	aux = list;
	while (aux)
	{
		if (aux->x == x)
		{
			if (aux->y == y)
				return (1);
		}
		aux = aux->next;
	}
	return (0);
}

void	is_accessible(t_map *map, int x, int y)
{
	t_node	*actual_pos;

	if (map->valid_map == 0)
		return (ft_free_node(map->route));
	actual_pos = init_node(map, x, y);
	if (is_saved(map->route, x, y) == 1)
		return (free(actual_pos));
	ft_nodeadd_back(&map->route, actual_pos);
	if (map->map[x][y] == '1')
		return (ft_free_node(map->route));
	if (map->map[x][y] == 'C' && map->count < map->collectables)
		map->count++;
	if (map->map[x][y] == 'E')
		map->gate_accessible = 1;
	if (map->count == map->collectables && map->gate_accessible == 1)
	{
		map->valid_map = 0;
		return (ft_free_node(map->route));
	}
	is_accessible(map, x, y - 1);
	is_accessible(map, x + 1, y);
	is_accessible(map, x, y + 1);
	is_accessible(map, x - 1, y);
	ft_free_node(map->route);
	return ;
}
