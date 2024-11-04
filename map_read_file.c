#include "so_long.h"

int	count_line(int fd)
{
	int	count;

	count = 0;
	while (get_next_line(fd))
		count++;
	return (count);
}
char	**map_init(mlx_data	*game)
{
	char	**map;
	int		fd;
	ssize_t	row;
	ssize_t	col;
	char	*line;

	fd = open("maps/wordl1.ber", O_RDONLY);
	printf("map init function called\n");
	if (fd == -1)
		return (0);

	row = 0;
	col = 0;
	map = (char **)malloc(sizeof(char *) * (count_line(fd) + 1));
	if (!map)
		return (0);
	fd = open("maps/wordl1.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != 0)
	{
		if (!col)
			col = ft_strlen(line);
		map[row] = malloc(col + 1);
		map[row][col] = '\0';
		free(line);
		row++;
	}
	close(fd);
	render_map(map, row, col, game);

	return (map);
	
}