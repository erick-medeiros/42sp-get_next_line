/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 05:38:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/28 05:40:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_next_line.h"

void	mandatory(void)
{
	int	fd;

	fd = open("./tests/test1", O_RDWR);
	check(1, get_next_line(fd), "ABCD\n");
	check(2, get_next_line(fd), "EFGH\n");
	check(3, get_next_line(fd), "IJKLMN");
	check(4, get_next_line(fd), NULL);
	close(fd);
	fd = open("./tests/test2", O_RDWR);
	check(5, get_next_line(fd), "\n");
	check(6, get_next_line(fd), NULL);
	close(fd);
	fd = open("./tests/test3", O_RDWR);
	check(7, get_next_line(fd), "0123456789012345678901234567890123456789\n");
	check(8, get_next_line(fd), "0");
	check(9, get_next_line(fd), NULL);
	close(fd);
	fd = open("./tests/test4", O_RDWR);
	check(10, get_next_line(fd), "\n");
	check(11, get_next_line(fd), "\n");
	check(12, get_next_line(fd), "\n");
	check(13, get_next_line(fd), NULL);
	close(fd);
	fd = -1;
	check(14, get_next_line(fd), NULL);
	fd = 1000;
	check(15, get_next_line(fd), NULL);
}

int	main(void)
{
	mandatory();
	return (0);
}
