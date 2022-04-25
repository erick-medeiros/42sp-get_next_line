/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:36 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/25 02:23:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_aloc(char **aloc, char *new_aloc)
{
	char	*temp;

	temp = *aloc;
	*aloc = new_aloc;
	free(temp);
}

char	*get_line(char **accumulator)
{
	char	*s;
	int		c;
	int		len;

	c = (int)(ft_strchr(*accumulator, '\n') - *accumulator) + 1;
	len = (int)(ft_strchr(*accumulator, '\0') - *accumulator);
	s = ft_substr(*accumulator, 0, c);
	update_aloc(accumulator, ft_substr(*accumulator, c, len));
	if (*accumulator[0] == '\0')
		update_aloc(accumulator, NULL);
	return (s);
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
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0 && accumulator == NULL)
	{
		free(buffer);
		return (NULL);
	}
	if (accumulator == NULL)
		update_aloc(&accumulator, ft_strdup(""));
	buffer[read_bytes] = '\0';
	update_aloc(&accumulator, ft_strjoin(accumulator, buffer));
	while (read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		update_aloc(&accumulator, ft_strjoin(accumulator, buffer));
	}
	line = get_line(&accumulator);
	if (read_bytes <= 0)
		update_aloc(&accumulator, NULL);
	free(buffer);
	return (line);
}
