#include "so_long.h"

int is_valid_move(mlx_data *game, int new_x, int new_y)
{
    int grid_x = new_x / game->map.wall.width;
    int grid_y = new_y / game->map.wall.height;

    // Check if the new position is within the bounds of the map
    if (grid_x >= 0 && grid_x < game->map.cols && 
        grid_y >= 0 && grid_y < game->map.rows)
    {
        // Check if the target cell is not a wall
        if (game->map.map[grid_y][grid_x] != '1')
        {
            return (1);  // Move is valid
        }
    }
    
    return (0);  // Move is invalid (blocked by wall or out of bounds)
}


int handle_input(int keysym, mlx_data *data)
{
	int new_x = data->player.pos_x;
	int new_y = data->player.pos_y;

	printf("The key %d was pressed\n", keysym);

	if (keysym == 53) // ESC key
	{
		printf("Esc pressed\n");
		kill_game_free(data->mlx, data->window);
		exit(0);
	}
	else if (keysym == 13) // W key
    	new_y -= 32;
	else if (keysym == 0) // A key
    	new_x -= 32;
	else if (keysym == 1) // S key
    	new_y += 32;
	else if (keysym == 2) // D key
    	new_x += 32;

// Update position if the move is valid
if (is_valid_move(data, new_x, new_y)) {
    data->player.pos_x = new_x;
    data->player.pos_y = new_y;
}

	// Clear and re-render the map with the updated player position
	mlx_clear_window(data->mlx, data->window);
	render_map(data->map.map, data->map.rows, data->map.cols, data);
	mlx_put_image_to_window(data->mlx, data->window, data->player.img, data->player.pos_x, data->player.pos_y);
	

	return (0);
}
