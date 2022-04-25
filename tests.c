/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:55:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/25 05:10:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	check_sucess(int id)
{
	printf("\e[32mTest %i: OK\n\e[00m", id);
}

void	check_error(int id, char const *gnl, char const *r)
{
	printf("\e[91mTest %i: KO\n\e[00m", id);
	printf("> (%s)\n", r);
	printf("< (%s)\n", gnl);
}

void	check(int id, int fd, char const *r)
{
	char	*gnl;

	gnl = get_next_line(fd);
	if (r == NULL)
	{
		if (gnl == NULL)
			check_sucess(id);
		else
			check_error(id, gnl, r);
	}
	else
	{
		if (gnl != NULL && strcmp(gnl, r) == 0)
			check_sucess(id);
		else
			check_error(id, gnl, r);
	}
	free(gnl);
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
		printf("argv %i\n", atoi(argv[1]));
	fd = open("./tests/test1", O_RDWR);
	check(1, fd, "ABCD\n");
	check(2, fd, "EFGH\n");
	check(3, fd, "IJKLMN");
	check(4, fd, NULL);
	close(fd);
	check(5, -1, NULL);
	fd = open("./tests/test2", O_RDWR);
	check(6, fd, "\n");
	check(7, fd, NULL);
	close(fd);
	fd = open("./tests/test3", O_RDWR);
	check(8, fd, "0123456789012345678901234567890123456789\n");
	check(9, fd, "0");
	check(10, fd, NULL);
	close(fd);
	fd = open("./tests/test4", O_RDWR);
	check(11, fd, "\n");
	check(12, fd, "\n");
	check(13, fd, "\n");
	check(14, fd, NULL);
	close(fd);
	return (0);
}
