/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:03:48 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/29 22:38:35 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	free_route(t_node *route)
{
	t_node	*aux;

	while (route)
	{
		aux = route;
		route = route->next;
		free(aux);
	}
}

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->rows)
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	free_route((*map)->route);
	free(*map);
}

void	free_textures(t_window *wd, t_textures **txt)
{
	mlx_destroy_image(wd->mlx_ptr, (*txt)->closed);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->black);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->wall);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->gate);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->collectable);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->logo);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[0][0]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[0][1]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[1][0]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[1][1]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[2][0]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[2][1]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[3][0]);
	mlx_destroy_image(wd->mlx_ptr, (*txt)->pac_man[3][1]);
	free((*txt));
}
