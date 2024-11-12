/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:03:15 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 17:09:32 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

int handle_valid_map_error(int count_e, int count_c, int count_p)
{
	if (count_e != 1)
	{
		printf("Error\nThere must be exactly one exit 'E'\n");
		return (0);
	}
	if (count_p != 1)
	{
		printf("Error\nThere must be exactly one player position 'P'\n");
		return (0);
	}
	if (count_c < 1)
	{
		printf("Error\nThere must be at least one collectible 'C'\n");
		return (0);
	}
	return (1);
}
int	call_clean_exit(t_mlx_data *game)
{
	clean_exit(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	game;

	if (argc != 2)
	{
		printf("please provide a valid map");
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.move_count = -1;
	game.map.count_collectible = 0;
	game.map.total_collectible_count = 0;
	if (!map_init(&game, argv[1]))
		return (0);
	set_window(&game);
	render_map(game.map.map, game.map.rows, game.map.cols, &game);
	game.first_render = 0;
	mlx_hook(game.window, 2, 1L << 0, handle_input, &game);
	mlx_hook(game.window, 17, 0, call_clean_exit, &game);
	mlx_loop(&game);
	return (0);
}
