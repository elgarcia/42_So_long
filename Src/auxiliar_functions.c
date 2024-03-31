/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:22:03 by eliagarc          #+#    #+#             */
/*   Updated: 2023/12/30 13:56:30 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/so_long.h"

void	ft_free(char **item, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(item[i]);
		i++;
	}
	free(item);
}

void	ft_nodeadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp && tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
		}
	}
}

void	ft_free_node(t_node *lst)
{
	t_node	*tmp;

	if (lst->next == NULL)
	{
		free(lst);
		lst = NULL;
	}
	else
	{
		tmp = lst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		free(tmp->next);
		tmp->next = NULL;
	}
}

void	loop_game(void *win_ptr, void *mlx_ptr, t_window *wd, \
int (*f)(int, t_window *))
{
	mlx_hook(win_ptr, 17, 1L << 17, &close_button, wd);
	mlx_hook(win_ptr, 2, 1L << 0, f, wd);
	mlx_loop(mlx_ptr);
}

int	init_window(char *argv, t_window **map_window)
{
	(*map_window) = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!*map_window)
		return (-1);
	if (read_map(argv, *map_window) == -1)
		exit(EXIT_FAILURE);
	(*map_window)->moves = 0;
	(*map_window)->mlx_ptr = mlx_init();
	if (!(*map_window)->mlx_ptr)
		return (-1);
	((*map_window))->win_ptr = mlx_new_window((*map_window)->mlx_ptr, \
	(*map_window)->game_map->columns * 30, (*map_window)->game_map->rows * 30, \
	"Pac Man | By eliagarc");
	if (!(*map_window)->win_ptr)
		return (free((*map_window)->mlx_ptr), -1);
	(*map_window)->wdow = 0;
	return (0);
}
