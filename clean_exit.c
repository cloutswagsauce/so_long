/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:38:50 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 17:09:57 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i++ < map.rows)
		free(map.map[i]);
	free(map.map);
}

void	clean_exit(t_mlx_data *game)
{
	mlx_destroy_image(game->mlx, game->map.wall.img);
	game->map.wall.img = NULL;
	mlx_destroy_image(game->mlx, game->map.free_space.img);
	game->map.free_space.img = NULL;
	mlx_destroy_image(game->mlx, game->map.collectible.img);
	game->map.collectible.img = NULL;
	mlx_destroy_image(game->mlx, game->map.exit_space.img);
	game->map.exit_space.img = NULL;
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = NULL;
	mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	free_map(game->map);
	exit(0);
}
