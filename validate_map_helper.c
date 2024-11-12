/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:11 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 14:26:59 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

int	increment_count(char c, int *countE, int *countC, int *countP)
{
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
			printf("Error\nMap is not surrounded by walls\n");
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

int	is_rectangular(t_map *map)
{
	int	i;
	int	len;
	int	current_len;

	if (!map || !map->map || !map->map[0])
		return (0);
	len = ft_strlen(map->map[0]);
	i = 0;
	while (i < map->rows)
	{
		current_len = ft_strlen(map->map[i]);
		if (!map->map[i] || current_len != len)
		{
			printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	map->cols = len;
	return (1);
}

int	all_reachable(t_map *map, int **visited, int i, int j)
{
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
