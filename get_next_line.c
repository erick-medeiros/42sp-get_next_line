/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:36 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/25 05:02:36 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	update_aloc(char **aloc, char *new_aloc)
{
	char	*temp;

	temp = *aloc;
	*aloc = new_aloc;
	free(temp);
}

char	*get_line(char **accumulator)
{
	size_t	c;
	size_t	len;
	char	*s;

	if (*accumulator == NULL)
		return (NULL);
	c = (size_t)(ft_strchr(*accumulator, '\n') - *accumulator) + 1;
	len = ft_strlen(*accumulator);
	s = ft_substr(*accumulator, 0, c);
	update_aloc(accumulator, ft_substr(*accumulator, c, len));
	if (*accumulator[0] == '\0')
		update_aloc(accumulator, NULL);
	return (s);
}

void	read_line(int fd, char **accumulator, char *buffer, int *read_bytes)
{
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes > 0)
	{
		if (*accumulator == NULL)
			update_aloc(accumulator, ft_strdup(""));
		buffer[*read_bytes] = '\0';
		update_aloc(accumulator, ft_strjoin(*accumulator, buffer));
		while (*read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
		{
			*read_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[*read_bytes] = '\0';
			update_aloc(accumulator, ft_strjoin(*accumulator, buffer));
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*accumulator = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0)
	{
		update_aloc(&accumulator, NULL);
		return (NULL);
	}
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_line(fd, &accumulator, buffer, &read_bytes);
	line = get_line(&accumulator);
	if (read_bytes <= 0)
		update_aloc(&accumulator, NULL);
	free(buffer);
	return (line);
}
