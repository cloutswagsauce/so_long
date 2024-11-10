#include "so_long.h"

int count_line(int fd) {
    int count = 0;
    char *line;
    while ((line = get_next_line(fd))) {
        count++;
        free(line);
    }
    close(fd);
    return count;
}


char **map_init(mlx_data *game, char *map_name) {
    int fd = open(map_name, O_RDONLY);
    if (fd == -1) return 0;

    int line_count = count_line(fd);
    game->map.rows = line_count;
    game->map.map = (char **)malloc(sizeof(char *) * (line_count + 1));
    if (!game->map.map) return 0;

    fd = open("maps/world1.ber", O_RDONLY);
    int i = 0;
    char *line;
    while (i < line_count && (line = get_next_line(fd))) {
        if (i == 0)
			game->map.cols = ft_strlen(line) - 1;
        game->map.map[i] = malloc(game->map.cols + 1);
        if (!game->map.map[i]) {
            free(line);
            return 0;
        }
        ft_strlcpy(game->map.map[i], line, game->map.cols + 1);
        free(line);
        i++;
    }
    game->map.map[game->map.rows] = 0;
    close(fd);

  	if (!validate_map(&game->map))
		clean_exit(game);
    return game->map.map;
}


