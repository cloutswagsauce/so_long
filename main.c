#include "so_long.h"

void kill_game_free(void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}


int handle_input(int keysym, mlx_data *data)
{
	printf("The key %d was pressed\n", keysym);
	if (keysym == 53) // Replace 53 with KEY_ESC constant if you defined it
	{
		printf("Esc pressed\n");
		kill_game_free(data->mlx, data->window);
		exit(0); // Exit cleanly with 0
	}
	else if (keysym == 13) // move w
		data ->player.pos_y -= 10;
	else if (keysym == 0) // move a
		data ->player.pos_x -= 10;
	else if (keysym == 1) // move down
		data->player.pos_y += 10;
	else if (keysym == 2)
		data->player.pos_x += 10;
	mlx_clear_window(data ->mlx, data-> window);
	mlx_put_image_to_window(data ->mlx, data -> window, data -> bg_img.img, data -> bg_img.pos_x, data -> bg_img.pos_y);
	mlx_put_image_to_window(data ->mlx, data -> window, data -> player.img, data -> player.pos_x, data -> player.pos_y);
	return (0);
}


int main(void)
{
	mlx_data	game;
	
	
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.window = mlx_new_window(game.mlx, 800, 600, "Kungfuryy");
	if (!game.window)
		return (1);
	game.img.img = mlx_new_image(game.mlx, 800, 600);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_len, &game.img.endian);
	game.bg_img.width = 800;
	game.bg_img.height = 600;

	game.bg_img.img = mlx_xpm_file_to_image(game.mlx, "graphics/background.xpm", &game.bg_img.width, &game.bg_img.height);
	if (!game.bg_img.img)
	{
		printf("Failed to load background image\n");
		return (1);
	}
	
	game.player.pos_x = 0;
	game.player.pos_y = 0;
	game.player.img = mlx_xpm_file_to_image(game.mlx, "graphics/tile001.xpm", &game.player.width, &game.player.height);

	if (!game.player.img)
	{
		printf("Failed to load hero image\n");
		return (1);
	}
	game.bg_img.pos_x = 0;
	game.bg_img.pos_y = 0;
	mlx_put_image_to_window(game.mlx, game.window, game.bg_img.img, game.bg_img.pos_y, game.bg_img.pos_y);
	mlx_put_image_to_window(game.mlx, game.window, game.player.img, game.player.pos_x, game.player.pos_y);
	mlx_hook(game.window, 2, 0L, handle_input, &game);

	// Start the event loop
	mlx_loop(game.mlx);

	// Clean up (this won't actually be reached as long as mlx_loop is running)
	kill_game_free(game.mlx, game.window);
	return (0);
}
