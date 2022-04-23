/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:55:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/23 18:55:38 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*file_path;
	char	*str;
	int		lines;
	int		max;

	file_path = "test";
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
		printf("%s\n", str);
		str = get_next_line(fd);
	}
	printf("lines %i\n", lines);
	return (0);
}
