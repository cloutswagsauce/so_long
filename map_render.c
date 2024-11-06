#include "so_long.h"

void	render_map(char	**map, int row, int col, mlx_data *game)
{
	int	current_row;
	int	current_col;
	int	x;
	int	y;

	current_col = 0;
	mlx_put_image_to_window(game->mlx, game->window, game->bg_img.img, game->bg_img.pos_x, game->bg_img.pos_y);
	
	while (current_col < col)
	{
		current_row = 0;
		while (current_row < row)
		{
			x = current_col * game ->map.wall.width;
			y = current_row * game ->map.wall.height;
			if (map[current_row][current_col] == '1')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.wall.img, x, y);
			else if (map[current_row][current_col] == '0')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.free_space.img, x, y);
			else if (map[current_row][current_col] == 'C')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.collectible.img, x, y);
			else if (map[current_row][current_col] == 'E')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.exit_space.img, x, y);
			else if (map[current_row][current_col] == 'P')
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
			
				mlx_put_image_to_window(game->mlx, game -> window, game -> player.img,game->player.pos_x , game->player.pos_y);
				printf("player xy position is: %d and %d ", game->player.pos_x, game->player.pos_y);
				

			}
				
			current_row++;
		}
		current_col++;
	}
}