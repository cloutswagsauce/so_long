/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:41:15 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/11 15:24:07 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	populate_rows(mlx_data *game, char *line, int line_count, int fd)
{
	int	i;

	i = 0;
	while (i < line_count && (line))
	{
		if (i == 0)
			game->map.cols = ft_strlen(line) - 1;
		game->map.map[i] = malloc(game->map.cols + 1);
		if (!game->map.map[i])
		{
			free(line);
			return (0);
		}
		ft_strlcpy(game->map.map[i], line, game->map.cols + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (1);
}

char	**map_init(mlx_data *game, char *map_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line_count = count_line(fd);
	game->map.rows = line_count;
	game->map.map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map.map)
		return (0);
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	populate_rows(game, line, line_count, fd);
	game->map.map[game->map.rows] = 0;
	close(fd);
	if (!validate_map(&game->map))
		clean_exit(game);
	return (game->map.map);
}
