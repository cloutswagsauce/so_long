#include "so_long.h"

int	count_line(int fd)
{
	int	count;
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
char	**map_init(mlx_data	*game)
{
	int		fd;
	char	*line;
	int		line_count;

	
	fd = open("maps/world1.ber", O_RDONLY);
	if (fd == -1)
		printf("failed to open map");
	line_count = count_line(fd);
	game->map.rows = 0;
	game->map.cols = 0;
	game ->map.map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game ->map.map)
		return (0);
	fd = open("maps/world1.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != 0)
	{
		printf("reading map: %s", line);
		if (!game -> map.cols)
			game ->map.cols = ft_strlen(line);
		game ->map.map[game->map.rows] = malloc(game->map.cols + 1);
		if (!game ->map.map[game->map.rows]) {
            free(line);
            return (0);
        }
		ft_strlcpy(game ->map.map[game->map.rows], line, game->map.cols + 1);
		free(line);
		game->map.rows++;
	}
	game ->map.map[game->map.rows] = 0;
	close(fd);
	

	return (0);
	
}