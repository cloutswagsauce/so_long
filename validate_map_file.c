/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:45 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/11 16:37:22 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (c == 'E')
				(*countE)++;
			else if (c == 'C')
				(*countC)++;
			else if (c == 'P')
				(*countP)++;
			else if (c != '0' && c != '1')
			{
				printf("Error\nInvalid character '%c' in map\n", c);
				return (0);
			}
			j ++;
		}
		i++;
	}
	return (1);
}

int	is_rectangular(t_map *map)
{
	int	i;
	int	len;

	if (!map->map[0])
		return (0);
	len = strlen(map->map[0]);
	i = 1;
	while (i < map->rows)
	{
		if (!map->map[i] || (int)strlen(map->map[i]) != len)
		{
			printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	map->cols = len;
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->cols)
	{
		if (map->map[0][j] != '1' || map->map[map->rows - 1][j] != '1')
		{
			printf("Error\nMap is not surrounded by walls (top/bottom row)\n");
			return (0);
		}
		j++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
		{
			printf("Error\nMap is not surrounded by walls (left/right column)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	find_start_position(t_map *map, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	printf("Error\nStarting point 'P' not found in the map\n");
	return (0);
}

void	flood_fill(t_map *map, int x, int y, int visited[map->rows][map->cols])
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

int	check_valid_path(t_map *map)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;
	int	visited[map->rows][map->cols];

	if (!find_start_position(map, &start_x, &start_y))
		return (0);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	flood_fill(map, start_x, start_y, visited);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E')
			&& !visited[i][j])
			{
				printf("Error\nNot all collectibles and exits are reachable\n");
				return (0);
			}
			j++;
		}
		i++;
	}
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
	if (count_e != 1)
	{
		printf("Error\nThere must be exactly one exit 'E'\n");
		return (0);
	}
	if (count_p != 1)
	{
		printf("Error\nThere must be exactly one player start 'P'\n");
		return (0);
	}
	if (count_c < 1)
	{
		printf("Error\nThere must be at least one collectible 'C'\n");
		return (0);
	}
	if (!is_surrounded_by_walls(map))
		return (0);
	if (!check_valid_path(map))
		return (0);
	map->total_collectible_count = count_c;
	return (1);
}
