#include "so_long.h"

int	**map(int argcm char *argv)
{
	int fd;

	fd = open("maps/world1.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	
}