/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 05:38:15 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/28 05:38:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_next_line(int fd);

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

void	check(int id, char *gnl, char const *r)
{
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
