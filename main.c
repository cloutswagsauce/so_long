#include "so_long.h"


int kill_game_free(void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
	mlx = 0;
	mlx_win = 0;
	return (0);
}
int handle_close(mlx_data *game)
{
    kill_game_free(game->mlx, game->window);
    exit(0); // Exit the program cleanly
    return (0);
}


int main(void)
{
	mlx_data	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	map_init(&game);
	set_window(&game);
	render_map(game.map.map, game.map.rows, game.map.rows, &game);
	
	mlx_hook(game.window,2, 1L<<0, handle_input, &game);
	printf("we got here");
	
	

	// Start the event loop
	mlx_loop(game.mlx);
	mlx_hook(game.window, 17, 1L << 17, handle_close, &game);

	// Clean up (this won't actually be reached as long as mlx_loop is running)
	kill_game_free(game.mlx, game.window);

	return (0);
}
