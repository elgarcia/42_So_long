/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:05:30 by eliagarc          #+#    #+#             */
/*   Updated: 2024/01/01 20:25:50 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

static int	store_map(t_map *map, int *fd, char *map_file)
{
	char	*aux;
	int		i;

	i = 0;
	*fd = open(map_file, O_RDONLY);
	if (*fd == -1)
		return (-1);
	map->map = (char **)ft_calloc(map->rows, sizeof(char *));
	if (!map->map)
		return (-1);
	aux = get_next_line(*fd);
	while (aux != NULL)
	{
		map->map[i] = ft_strdup(aux);
		if (!(map)->map[i])
			return (free(aux), ft_free(map->map, map->rows), -1);
		if ((int)ft_strlen(aux) - 1 != map->columns)
			return (free(aux), ft_free(map->map, map->rows), -1);
		free(aux);
		aux = get_next_line(*fd);
		i++;
	}
	close(*fd);
	return (0);
}

int	assign_map(int *fd, char *map_file, t_map *map)
{
	char	*aux;

	map->columns = 0;
	map->rows = 0;
	*fd = open(map_file, O_RDONLY);
	if (*fd == -1)
		return (ft_printf("Invalid file!\n"), -1);
	aux = get_next_line(*fd);
	while (aux != NULL)
	{
		if (map->rows == 0)
			map->columns = (int)ft_strlen(aux) - 1;
		if (map->columns == 0)
		{
			close(*fd);
			return (free(aux), ft_printf("Invalid map!\n"), -1);
		}
		free(aux);
		aux = get_next_line(*fd);
		map->rows++;
	}
	close(*fd);
	if (store_map(map, fd, map_file) == -1)
		return (ft_printf("Invalid map!\n"), -1);
	return (0);
}

int	check_dimensions(t_map *map)
{
	if (map->columns < 3 || map->rows < 3)
		return (-1);
	if (map->columns == 3)
	{
		if (map->rows < 5)
			return (-1);
	}
	if (map->rows == 3)
	{
		if (map->columns < 5)
			return (-1);
	}
	return (0);
}

int	check_map(t_window *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->game_map->rows)
	{
		while (j < map->game_map->columns)
		{
			if (check_chars(map, i, j) == -1)
				return (ft_printf("Invalid characters! -> "), -1);
			if (check_borders(map->game_map, i, j) == -1)
				return (ft_printf("Invalid borders! -> "), -1);
			j++;
		}
		j = 0;
		i++;
	}
	if (map->game_map->collectables == 0 || map->game_map->players != 1 \
	|| map->game_map->gate != 1)
		return (-1);
	return (0);
}

int	read_map(char *map_file, t_window *map)
{
	int		fd;

	map->game_map = (t_map *)ft_calloc(1, sizeof(t_map));
	map->player = (t_player *)ft_calloc(1, sizeof(t_player));
	map->player->win = 0;
	map->game_map->collectables = 0;
	map->game_map->route = NULL;
	map->game_map->count = 0;
	map->game_map->valid_map = -1;
	map->game_map->players = 0;
	map->game_map->gate = 0;
	map->game_map->gate_accessible = 0;
	if (ft_strncmp(map_file + ((int)ft_strlen(map_file) - 4), ".ber", 4))
		return (ft_printf("Invalid extension!\n"), -1);
	if (assign_map(&fd, map_file, map->game_map) == -1)
		return (-1);
	if (check_dimensions(map->game_map) == -1)
		return (ft_printf("Invalid dimensions map!\n"), -1);
	if (check_map(map) == -1)
		return (ft_printf("Invalid map!\n"), -1);
	is_accessible(map->game_map, map->player->x, map->player->y);
	if (map->game_map->valid_map == -1)
		return (ft_printf("Invalid path map!\n"), -1);
	return (ft_printf("The map is correct\n"), 0);
}
