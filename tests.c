#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*file_path = "test";
	char	*str;
	int		lines;
	int		max;

	fd = open(file_path, O_RDWR);
	if (fd < 0)
		return (1);
	lines = 0;
	str = get_next_line(fd);
	max = 99999;
	if (argc == 2)
		max = atoi(argv[1]);
	while (str != NULL && lines < max)
	{
		lines++;
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("\nlines %i\n", lines);
	return (0);
}
