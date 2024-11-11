/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:03:15 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/11 16:59:02 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	call_clean_exit(mlx_data *game)
{
	clean_exit(game);
	return (0);
}

int	main(int argc, char **argv)
{
	mlx_data	game;

	if (argc != 2)
	{
		printf("please provide a valid map");
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.map.count_collectible = 0;
	game.map.total_collectible_count = 0;
	map_init(&game, argv[1]);
	set_window(&game);
	render_map(game.map.map, game.map.rows, game.map.cols, &game, 1);
	mlx_hook(game.window, 2, 1L << 0, handle_input, &game);
	mlx_hook(game.window, 17, 0, call_clean_exit, &game);
	mlx_loop(&game);
	return (0);
}
