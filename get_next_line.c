/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:36 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/23 18:56:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*accumulator = NULL;
	char		*buffer;
	char		*line;
	char		*temp;
	int			start_split;
	int			end_split;
	int			read_bytes;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (accumulator == NULL)
		accumulator = ft_strdup("");
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (NULL);
	accumulator = ft_strjoin(accumulator, buffer);
	while (read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		accumulator = ft_strjoin(accumulator, buffer);
	}
	temp = accumulator;
	start_split = (int)(ft_strchr(temp, '\n') - temp);
	end_split = (int)(ft_strchr(temp, '\0') - temp);
	line = ft_substr(temp, 0, start_split);
	accumulator = ft_substr(temp, start_split + 1, end_split);
	free(temp);
	free(buffer);
	return (line);
}
