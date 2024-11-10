#include "so_long.h"
#include <stdio.h>
#include <string.h>

int validate_map_characters(t_map *map, int *count_E, int *count_C, int *count_P)
{
    int i, j;
    char c;
    *count_E = 0;
    *count_C = 0;
    *count_P = 0;
    i = 0;
    while (i < map->rows)
    {	
        j = 0;
        while (j < map->cols)
        {
            c = map->map[i][j];
            if (c == 'E')
                (*count_E)++;
            else if (c == 'C')
            {
                (*count_C)++;
				printf("%d", *count_C);
            }
            else if (c == 'P')
                (*count_P)++;
            else if (c != '0' && c != '1')
            {
                printf("Error\nInvalid character '%c' in map\n", c);
                return 0;
            }
            j++;  // Increment j here
        }
        i++;  // Increment i here
    }
    return 1;
}


int is_rectangular(t_map *map)
{
    int i;
    int len = strlen(map->map[0]);
    i = 1;
    while (i < map->rows)
    {
        if ((int)strlen(map->map[i]) != len)
        {
            printf("Error\nMap is not rectangular\n");
            return 0;
        }
        i++;  // Increment i here
    }
    map->cols = len;
    return 1;
}



int is_surrounded_by_walls(t_map *map)
{
    int i, j;

    // Check first and last row
    for (j = 0; j < map->cols; j++)
    {
        if (map->map[0][j] != '1' || map->map[map->rows - 1][j] != '1')
        {
            printf("Error\nMap is not surrounded by walls (top/bottom row)\n");
            return 0;
        }
    }

    // Check first and last column
    for (i = 0; i < map->rows; i++)
    {
        if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
        {
            printf("Error\nMap is not surrounded by walls (left/right column)\n");
            return 0;
        }
    }

    return 1;
}

int find_start_position(t_map *map, int *start_x, int *start_y)
{
    int i, j;
	i = 0;
    while(i++ < map->rows)
    {
		j = 0;
        while (j++ < map->cols)
        {
            if (map->map[i][j] == 'P')
            {
                *start_x = i;
                *start_y = j;
                return 1;
            }
        }
    }
    printf("Error\nStarting point 'P' not found in the map\n");
    return 0;
}

void flood_fill(t_map *map, int x, int y, int visited[map->rows][map->cols])
{
    if (x < 0 || x >= map->rows || y < 0 || y >= map->cols)
        return;
    if (visited[x][y])
        return;
    if (map->map[x][y] == '1')
        return;
    visited[x][y] = 1;

    flood_fill(map, x + 1, y, visited);
    flood_fill(map, x - 1, y, visited);
    flood_fill(map, x, y + 1, visited);
    flood_fill(map, x, y - 1, visited);
}

int check_valid_path(t_map *map)
{
    int start_x, start_y;
    int i, j;
    int visited[map->rows][map->cols];

    if (!find_start_position(map, &start_x, &start_y))
        return 0;

    // Initialize visited array
    for (i = 0; i < map->rows; i++)
    {
        for (j = 0; j < map->cols; j++)
        {
            visited[i][j] = 0;
        }
    }

    // Perform flood fill
    flood_fill(map, start_x, start_y, visited);

    // Check if all 'C's and 'E's are reachable
    for (i = 0; i < map->rows; i++)
    {
        for (j = 0; j < map->cols; j++)
        {
            if ((map->map[i][j] == 'C' || map->map[i][j] == 'E') && !visited[i][j])
            {
                printf("Error\nNot all collectibles and exits are reachable\n");
                return 0;
            }
        }
    }

    return 1;
}

int validate_map(t_map *map)
{
    int count_E;
	int count_C;
	int count_P;

    if (!is_rectangular(map))
        return 0;

    if (!validate_map_characters(map, &count_E, &count_C, &count_P))
        return 0;

    if (count_E != 1)
    {
        printf("Error\nThere must be exactly one exit 'E'\n");
        return 0;
    }

    if (count_P != 1)
    {
        printf("Error\nThere must be exactly one player start 'P'\n");
        return 0;
    }

    if (count_C < 1)
    {
        printf("Error\nThere must be at least one collectible 'C'\n");
        return 0;
    }

    if (!is_surrounded_by_walls(map))
        return 0;

    if (!check_valid_path(map))
        return 0;
	map->total_collectible_count = count_C;
    return 1;
}
