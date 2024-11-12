/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:00:19 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 17:08:45 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_S 32

# include "includes/minilibx/mlx.h"
# include "includes/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

typedef struct s_mlx_img
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
}			t_mlx_img;

typedef struct s_map_elem
{
	void	*img;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}			t_map_elem;

typedef struct t_map
{
	char		**map;
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
	int			rows;
	int			count_collectible;
	int			total_collectible_count;
	int			cols;
	t_map_elem	wall;
	t_map_elem	free_space;
	t_map_elem	collectible;
	t_map_elem	exit_space;

}			t_map;

typedef struct s_entity
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


}			t_entity;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
	t_mlx_img	img;
	t_entity	player;
	t_map	map;
	int		first_render;
	int		move_count;
	
	
}			t_mlx_data;

int		handle_input(int keysym, t_mlx_data *data);
char	**map_init(t_mlx_data *game, char *map_name);
int		render_map(char	**map, int row, int col, t_mlx_data *game);
int		set_window(t_mlx_data *game);
int		is_valid_move(t_mlx_data *game, int new_x, int new_y);
int		validate_map(t_map *game);
void	clean_exit(t_mlx_data *game);
int		find_start_position(t_map *map, int *start_x, int *start_y);
int		is_surrounded_by_walls(t_map *map);
int		is_rectangular(t_map *map);
int		increment_count(char c, int *countE, int *countC, int *countP);
int		all_reachable(t_map *map, int **visited,  int i, int j);
int		handle_valid_map_error(int count_e, int count_c, int count_p);

#endif