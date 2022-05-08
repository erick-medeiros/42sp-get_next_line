/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 05:38:23 by eandre-f          #+#    #+#             */
/*   Updated: 2022/05/08 23:31:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_next_line_bonus.h"

void	bonus(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	printf("\e[33mBonus\e[00m\n");
	printf("BUFFER_SIZE %d\n", BUFFER_SIZE);
	fd1 = open("test1", O_RDWR);
	fd2 = open("test2", O_RDWR);
	fd3 = open("test3", O_RDWR);
	fd4 = open("test4", O_RDWR);
	check(1, get_next_line(fd1), "ABCD\n");
	check(2, get_next_line(fd2), "\n");
	check(3, get_next_line(fd1), "EFGH\n");
	check(4, get_next_line(fd3), "0123456789012345678901234567890123456789\n");
	check(5, get_next_line(fd1), "IJKLMN");
	check(6, get_next_line(fd1), NULL);
	check(7, get_next_line(fd4), "\n");
	check(8, get_next_line(fd2), NULL);
	check(9, get_next_line(fd4), "\n");
	check(10, get_next_line(1000), NULL);
	check(11, get_next_line(fd3), "0");
	check(12, get_next_line(fd3), NULL);
	check(13, get_next_line(fd4), "\n");
	check(14, get_next_line(fd4), NULL);
	check(15, get_next_line(-1), NULL);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

int	main(void)
{
	bonus();
	return (0);
}
