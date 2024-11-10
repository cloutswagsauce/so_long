#include "so_long.h"
void free_map(t_map map)
{
	int	i;

	i = 0;
	while (i++ < map.rows)
		free(map.map[i]);
	free(map.map);

}
void clean_exit(mlx_data *game)
{
	if (game->map.wall.img) {
        mlx_destroy_image(game->mlx, game->map.wall.img);
        game->map.wall.img = NULL;  // Set to NULL to avoid double-freeing
    }

    if (game->map.free_space.img) {
        mlx_destroy_image(game->mlx, game->map.free_space.img);
        game->map.free_space.img = NULL;
    }

    if (game->map.collectible.img) {
        mlx_destroy_image(game->mlx, game->map.collectible.img);
        game->map.collectible.img = NULL;
    }

    if (game->map.exit_space.img) {
        mlx_destroy_image(game->mlx, game->map.exit_space.img);
        game->map.exit_space.img = NULL;
    }

    if (game->player.img) {
        mlx_destroy_image(game->mlx, game->player.img);
        game->player.img = NULL;
    }

    if (game->window) {
        mlx_destroy_window(game->mlx, game->window);
        game->window = NULL;
    }
	free_map(game->map);
	mlx_destroy_window(game, game->window);
	exit(0);
}
