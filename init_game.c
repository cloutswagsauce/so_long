
#include "so_long.h"

int load_image_elems(mlx_data *game)
{
	
	game->map.wall.img = mlx_xpm_file_to_image(game->mlx, "graphics/map/wall1.xpm", &game->map.wall.width, &game->map.wall.height);
	if (!game->map.wall.img)
	{
		printf("Failed to load wall image\n");
		return (1);
	}
	game->map.free_space.img = mlx_xpm_file_to_image(game->mlx, "graphics/map/free4.xpm", &game->map.free_space.width, &game->map.free_space.height);
	if (!game->map.free_space.img)
	{
		printf("Failed to load free space image\n");
		return (1);
	}
	game->map.collectible.img = mlx_xpm_file_to_image(game->mlx, "graphics/map/collectible.xpm", &game->map.collectible.width, &game->map.collectible.height);
	if (!game->map.collectible.img)
	{
		printf("Failed to load free space image\n");
		return (1);
	}
	game->map.exit_space.img = mlx_xpm_file_to_image(game->mlx, "graphics/map/exit1.xpm", &game->map.exit_space.width, &game->map.exit_space.height);
	if (!game->map.exit_space.img)
	{
		printf("Failed to load free space image\n");
		return (1);
	}

	
	game->player.img = mlx_xpm_file_to_image(game->mlx, "graphics/sonic.xpm", &game->player.width, &game->player.height);

	if (!game->player.img)
	{
		printf("Failed to load hero image\n");
		return (1);
	}

	return (0);

}


int set_window(mlx_data *game)
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
	game->player.pos_x = 0;
	game->player.pos_y = 0;


	window_width = game ->map.wall.width * game ->map.cols;
	if (!window_width)
		printf("failed to build window width");
	window_height = game ->map.wall.height * game ->map.rows;
	if (!window_height)
		printf("failed to build window height");

	game->window = mlx_new_window(game->mlx, window_width, window_height, "Kungfuryy");
	if (!game->window)
	{
		printf("game window failed to create");
		return (1);
	}
	game->player.width = 32;
	game->player.height = 32;
	game->img.img = mlx_new_image(game->mlx, window_width, window_height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_len, &game->img.endian);
	load_image_elems(game);
	return (0);
}
