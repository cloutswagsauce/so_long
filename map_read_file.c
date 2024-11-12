/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:41:15 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/12 17:10:20 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	populate_rows(t_mlx_data *game, char *line, int line_count, int fd)
{
	int	i;
	int	line_length;

	i = 0;
	while (i < line_count && line)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line_length--;
		if (i == 0)
			game->map.cols = line_length;
		game->map.map[i] = malloc(line_length + 1);
		if (!game->map.map[i])
		{
			free(line);
			return (0);
		}
		ft_strlcpy(game->map.map[i], line, line_length + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (1);
}

char	**map_init(t_mlx_data *game, char *map_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line_count = count_line(fd);
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	game->map.rows = line_count;
	game->map.map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map.map || !populate_rows(game, line, line_count, fd))
	{
		close(fd);
		return (0);
	}
	game->map.map[game->map.rows] = NULL;
	close(fd);
	if (!validate_map(&game->map))
		return (0);
	return (game->map.map);
}
