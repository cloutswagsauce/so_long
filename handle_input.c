/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:38:14 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:19 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(mlx_data *game, int new_x, int new_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = new_x / game->map.wall.width;
	grid_y = new_y / game->map.wall.height;
	if (grid_x >= 0 && grid_x < game->map.cols &&
		grid_y >= 0 && grid_y < game->map.rows)
	{
		if (game->map.map[grid_y][grid_x] != '1')
		{
			if (game->map.map[grid_y][grid_x] == 'C')
			{
				game->map.count_collectible++;
				game->map.map[grid_y][grid_x] = '0';
			}
			if (game->map.map[grid_y][grid_x] == 'E')
			{
				if (game->map.total_collectible_count ==
					game->map.count_collectible)
					clean_exit(game);
			}
			return (1);
		}
	}
	return (0);
}

void	wasd(int keysym, mlx_data *data, int *new_x, int *new_y)
{
	if (keysym == 53)
	{
		printf("Esc pressed\n");
		clean_exit(data);
		exit(0);
	}
	else if (keysym == 13)
		*new_y -= 32;
	else if (keysym == 0)
		*new_x -= 32;
	else if (keysym == 1)
		*new_y += 32;
	else if (keysym == 2)
		*new_x += 32;
}

int	handle_input(int keysym, mlx_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player.pos_x;
	new_y = data->player.pos_y;
	wasd(keysym, data, &new_x, &new_y);
	if (is_valid_move(data, new_x, new_y))
	{
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
	}
	mlx_clear_window(data->mlx, data->window);
	render_map(data->map.map, data->map.rows, data->map.cols, data, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->player.img, data->player.pos_x, data->player.pos_y);
	return (0);
}
