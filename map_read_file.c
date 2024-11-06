#include "so_long.h"

int	count_line(int fd)
{
	int		count;
	char	*line;
	

	count = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**map_init(mlx_data *game)
{
	int		fd;
	char	*line;
	int		line_count;
	int		i;
	fd = open("maps/world1.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	line_count = count_line(fd);
	game->map.rows = line_count;
	game->map.map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map.map)
		return (0);
	fd = open("maps/world1.ber", O_RDONLY);
	i = 0;
	while (i < line_count)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (i == 0) // Set columns only once, as all lines have the same length
			game->map.cols = ft_strlen(line);
		game->map.map[i] = malloc(game->map.cols + 1);
		if (!game->map.map[i])
		{
			free(line);
			return (0);
		}
		ft_strlcpy(game->map.map[i], line, game->map.cols + 1);
		free(line);
		i++;
	}
	game ->map.map[game->map.rows] = 0;
	close(fd);
	return (game->map.map);
}
