#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*file_path = "test";
	char	*str;

	fd = open(file_path, O_RDWR);
	if (fd < 0)
		return (1);
	str = get_next_line(fd);
	while (str != NULL)
		str = get_next_line(fd);
	write(1, "\n", 1);
	return (0);
}
