/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 05:47:35 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/25 05:48:20 by eandre-f         ###   ########.fr       */
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

char	*get_line(char **acc)
{
	size_t	c;
	char	*s;

	if (*acc == NULL)
		return (NULL);
	c = (size_t)(ft_strchr(*acc, '\n') - *acc) + 1;
	s = ft_substr(*acc, 0, c);
	update_aloc(acc, ft_substr(*acc, c, ft_strlen(*acc)));
	if (*acc[0] == '\0')
		update_aloc(acc, NULL);
	return (s);
}

void	read_line(int fd, char **acc, char *buffer, int *read_bytes)
{
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes > 0)
	{
		if (*acc == NULL)
			update_aloc(acc, ft_strdup(""));
		buffer[*read_bytes] = '\0';
		update_aloc(acc, ft_strjoin(*acc, buffer));
		while (*read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
		{
			*read_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[*read_bytes] = '\0';
			update_aloc(acc, ft_strjoin(*acc, buffer));
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*acc = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0)
	{
		update_aloc(&acc, NULL);
		return (NULL);
	}
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_line(fd, &acc, buffer, &read_bytes);
	line = get_line(&acc);
	free(buffer);
	return (line);
}
