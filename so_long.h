#ifndef SO_LONG

#define SO_LONG



typedef struct mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}			mlx_img;

typedef struct map_elem
{
	void	*img;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}			map_elem;

typedef struct t_map
{
	char		**map;
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
	int			rows;
	int			cols;
	map_elem	wall;
	map_elem	free_space;
	map_elem	collectible;
	map_elem	exit_space;

}			t_map;

typedef struct entity
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;


}			entity;

typedef struct mlx_data
{
	void	*mlx;
	void	*window;
	mlx_img	img;
	entity	player;
	mlx_img	bg_img;
	t_map	map;
	
}			mlx_data;

#define start_x 0
#define start_y 0


#include "includes/minilibx/mlx.h"
#include "includes/libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int		handle_input(int keysym, mlx_data *data);
void 	kill_game_free(void *mlx, void *mlx_win);
char	**map_init(mlx_data *game);
void	render_map(char	**map, int row, int col, mlx_data *game);
int		set_window(mlx_data *game);
int		is_valid(mlx_data *game, int new_x, int new_y);

#endif