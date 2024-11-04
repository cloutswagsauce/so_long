#include "so_long.h"

void	render_map(char	**map, int row, int col, mlx_data *game)
{
	int	current_row;
	int	current_col;

	current_row = 0;

	while (current_row < row)
	{
		current_col = 0;
		while (current_col < col)
		{
			if (map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.wall.img, game -> map.wall.width,game -> map.wall.width);
			else if (map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game -> window, game -> map.free_space.img, game -> map.free_space.width, game -> map.free_space.width);
			col++;
		}
		row++;
	}
}