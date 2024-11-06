/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:27 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/06 13:31:23 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(mlx_data *game, int new_x, int new_y)
{
	int grid_x = new_x / game->map.wall.width;
	int grid_y = new_y / game->map.wall.height;
	printf("valid move getting called");

	if (grid_x >= 0 && grid_x <= game->map.cols  && grid_y >= 0 && grid_y <= game->map.rows
	&& game->map.map[grid_x][grid_y] != '1')
	{
		return (1);
	}
	else
	{
		return (0);
	}


}

int handle_input(int keysym, mlx_data *data)
{
	int new_x;
	int	new_y;

	new_x = data->player.pos_x;
	new_y = data->player.pos_y;
	printf("The key %d was pressed\n", keysym);
	if (keysym == 53) // Replace 53 with KEY_ESC constant if you defined it
	{
		printf("Esc pressed\n");
		kill_game_free(data->mlx, data->window);
		exit(0); // Exit cleanly with 0
	}
	else if (keysym == 13) // move w
		new_y -= data->map.wall.height;
	else if (keysym == 0) // move a
		new_x -= data->map.wall.width;
	else if (keysym == 1) // move down
		new_y += data->map.wall.height;
	else if (keysym == 2)
		new_x += data->map.wall.width;
	printf("new x is %d, ", new_x);
	if (is_valid_move(data, new_x, new_y))
	{
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
	}
	printf("x is at %d, ", data->player.pos_x);
	mlx_clear_window(data ->mlx, data-> window);
	mlx_put_image_to_window(data ->mlx, data -> window, data -> bg_img.img, data -> bg_img.pos_x, data -> bg_img.pos_y);
	render_map(data->map.map, data->map.rows, data->map.cols, data);
	mlx_put_image_to_window(data ->mlx, data -> window, data -> player.img, data -> player.pos_x, data -> player.pos_y);
	return (0);
}

