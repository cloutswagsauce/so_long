#include "so_long.h"

void kill_game_free(void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}


int main(void)
{
	mlx_data	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	map_init(&game);
	printf("printing rows %d", game.map.rows);
	printf("printing cols %d", game.map.cols);
	set_window(&game);
	render_map(game.map.map, game.map.rows, game.map.rows, &game);
	
	mlx_hook(game.window, 2, 0L, handle_input, &game);
	printf("we got here");
	
	

	// Start the event loop
	mlx_loop(game.mlx);

	// Clean up (this won't actually be reached as long as mlx_loop is running)
	kill_game_free(game.mlx, game.window);

	return (0);
}
