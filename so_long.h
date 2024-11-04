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
}			map_elem;

typedef struct t_map
{
	char	**map;
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	int		collectibles;

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
	
}			mlx_data;

#define start_x 0
#define start_y 0


#include "includes/minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>



#endif