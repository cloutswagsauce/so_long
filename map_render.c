#include "so_long.h"

int	render_map(char	**map, int row, int col, mlx_data *game, int first)
{
	int	current_row;
	int	current_col;
	int	x;
	int	y;

	current_row = 0;
	while (current_row < row)
	{
		current_col = 0;
		while (current_col < col)
		{
			x = current_col * game ->map.wall.width;
			y = current_row * game ->map.wall.height;
			if (map[current_row][current_col] == '1')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.wall.img, x, y);
			else if (map[current_row][current_col] == 'P')
			{
				if (first == 1)
				{
					game->player.pos_x = x;
					game->player.pos_y = y;
					mlx_put_image_to_window(game->mlx, game -> window, game -> player.img, x , y);
					printf("bro spawned");
				}

				mlx_put_image_to_window(game->mlx, game -> window, game -> map.free_space.img, x, y);
			}
			else if (map[current_row][current_col] == '0')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.free_space.img, x, y);
			else if (map[current_row][current_col] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.free_space.img, x, y);
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.collectible.img, x, y);
			}
			else if (map[current_row][current_col] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.free_space.img, x, y);
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.exit_space.img, x, y);
			}
			
				
			current_col++;
		}
		current_row++;
	}
	
	return (0);
}
