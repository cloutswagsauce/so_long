/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:06:51 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/11 13:36:51 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_image_elems(mlx_data *game)
{
	game->map.wall.img = mlx_xpm_file_to_image(game->mlx,
			"graphics/map/wall1.xpm", &game->map.wall.width,
			&game->map.wall.height);
	game->map.free_space.img = mlx_xpm_file_to_image(game->mlx,
			"graphics/map/dirt.xpm", &game->map.free_space.width,
			&game->map.free_space.height);
	game->map.collectible.img = mlx_xpm_file_to_image(game->mlx,
			"graphics/map/gem.xpm", &game->map.collectible.width,
			&game->map.collectible.height);
	game->map.exit_space.img = mlx_xpm_file_to_image(game->mlx,
			"graphics/map/door.xpm", &game->map.exit_space.width,
			&game->map.exit_space.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"graphics/steve.xpm", &game->player.width,
			&game->player.height);
	return (0);
}

int	set_window(mlx_data *game)
{
	int	window_width;
	int	window_height;

	game->map.wall.width = 32;
	game->map.wall.height = 32;
	game->map.free_space.width = 32;
	game->map.free_space.height = 32;
	game->map.exit_space.width = 32;
	game->map.exit_space.height = 32;
	game->player.width = 32;
	game->player.height = 32;
	window_width = game ->map.wall.width * game ->map.cols;
	if (!window_width)
		printf("failed to build window width");
	window_height = game ->map.wall.height * game ->map.rows;
	if (!window_height)
		printf("failed to build window height");
	game->window = mlx_new_window(game->mlx,
			window_width, window_height, "SO_LONG DELUXE");
	game->img.img = mlx_new_image(game->mlx, window_width, window_height);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_len, &game->img.endian);
	load_image_elems(game);
	return (0);
}
