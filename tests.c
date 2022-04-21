#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("\n");
	return (0);
}
