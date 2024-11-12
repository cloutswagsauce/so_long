/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:07 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 17:10:43 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

int	player_to_window(t_mlx_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game -> window,
		game -> map.free_space.img, x, y);
	if (game->first_render == 1)
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.img, game->player.pos_x, game->player.pos_y);
	}
	return (1);
}

int	image_to_window(t_mlx_data *game, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game -> window,
			game -> map.wall.img, x, y);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game -> window,
			game -> map.free_space.img, x, y);
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game -> window,
			game -> map.free_space.img, x, y);
		mlx_put_image_to_window(game->mlx, game -> window,
			game -> map.exit_space.img, x, y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game -> window,
			game -> map.free_space.img, x, y);
		mlx_put_image_to_window(game->mlx, game -> window,
			game -> map.collectible.img, x, y);
	}
	return (1);
}

int	render_map(char	**map, int row, int col, t_mlx_data *game)
{
	int		current_row;
	int		current_col;
	int		x;
	int		y;
	char	c;

	current_row = 0;
	while (current_row < row)
	{
		current_col = 0;
		while (current_col < col)
		{
			x = current_col * game ->map.wall.width;
			y = current_row * game ->map.wall.height;
			c = map[current_row][current_col];
			if (c == 'P')
				player_to_window(game, x, y);
			else
				image_to_window(game, x, y, c);
			current_col++;
		}
		current_row++;
	}
	return (0);
}
