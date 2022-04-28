/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 05:47:35 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/28 06:27:59 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	update_aloc(char **aloc, char *new_aloc)
{
	char	*temp;

	temp = *aloc;
	*aloc = new_aloc;
	free(temp);
}

static char	*get_line(char **acc)
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

static void	read_line(int fd, char **acc, char *buffer, int *read_bytes)
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

//sysconf(_SC_OPEN_MAX)

char	*get_next_line(int fd)
{
	static char	*fd_acc[4000000];
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0 || fd > 4000000 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_line(fd, &fd_acc[fd], buffer, &read_bytes);
	line = get_line(&fd_acc[fd]);
	free(buffer);
	return (line);
}
