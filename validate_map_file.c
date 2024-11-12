/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:14:26 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 16:32:29 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"
#include <stdio.h>
#include <string.h>

int	validate_map_characters(t_map *map, int *countE, int *countC, int *countP)
{
	int		i;
	int		j;
	char	c;

	*countE = 0;
	*countC = 0;
	*countP = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			c = map->map[i][j];
			increment_count(c, countE, countC, countP);
			j ++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_map *map, int x, int y, int **visited)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols)
		return ;
	if (visited[x][y])
		return ;
	if (map->map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

int	**allocate_mem(int rows, int cols)
{
	int	**temp;
	int	i;

	temp = (int **)malloc(sizeof(int *) * rows);
	if (!temp)
		return (0);
	i = 0;
	while (i < rows)
	{
		temp[i] = (int *)malloc(sizeof(int) * cols);
		if (!temp[i])
		{
			while (i > 0)
				free(temp[--i]);
			free(temp);
			return (0);
		}
		i++;
	}
	return (temp);
}

int	check_valid_path(t_map *map)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;
	int	**visited;

	if (!find_start_position(map, &start_x, &start_y))
		return (0);
	i = 0;
	visited = allocate_mem(map->rows, map->cols);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
			visited[i][j++] = 0;
		i++;
	}
	flood_fill(map, start_x, start_y, visited);
	if (!all_reachable(map, visited, i, j))
		return (0);
	return (1);
}

int	validate_map(t_map *map)
{
	int	count_e;
	int	count_c;
	int	count_p;

	if (!is_rectangular(map))
		return (0);
	if (!validate_map_characters(map, &count_e, &count_c, &count_p))
		return (0);
	if (!handle_valid_map_error(count_e, count_c, count_p))
		return (0);
	if (!is_surrounded_by_walls(map))
		return (0);
	if (!check_valid_path(map))
		return (0);
	map->total_collectible_count = count_c;
	return (1);
}
