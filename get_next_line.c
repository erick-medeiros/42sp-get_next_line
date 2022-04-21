/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:36 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/21 17:38:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*accumulator;
	int		read_bytes;

	accumulator = "";
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (NULL);
	while (read_bytes > 0)
	{
		accumulator = ft_strjoin(accumulator, buffer);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_strdup(accumulator));
}
