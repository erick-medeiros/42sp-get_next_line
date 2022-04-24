/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:55:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/25 01:15:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	check(int id, int fd, char const *r)
{
	char	*gnl;

	gnl = get_next_line(fd);
	if ((r == NULL && gnl == NULL) || (r != NULL && strcmp(gnl, r) == 0))
	{
		printf("\e[32mTest %i: OK\n\e[00m", id);
	}
	if ((r == NULL && gnl != NULL) || (r != NULL && strcmp(gnl, r) != 0))
	{
		printf("\e[91mTest %i: KO\n\e[00m", id);
		printf("> (%s)\n", r);
		printf("< (%s)\n", gnl);
	}
	free(gnl);
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
		printf("argv %i\n", atoi(argv[1]));
	fd = open("./tests/test1", O_RDWR);
	check(1, fd, "ABCD");
	check(2, fd, "EFGH");
	check(3, fd, "IJKLMN");
	check(4, fd, NULL);
	close(fd);
	check(5, -1, NULL);
	fd = open("./tests/test2", O_RDWR);
	check(6, fd, "\n");
	check(7, fd, NULL);
	close(fd);
	return (0);
}
