/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 05:47:41 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/27 16:24:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	caract;
	char	*sc;

	caract = (unsigned char) c;
	sc = (char *)s;
	i = 0;
	while (sc[i] != '\0')
	{
		if (sc[i] == caract)
			return (&sc[i]);
		i++;
	}
	if (caract == '\0')
		return (&sc[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*s;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s = (char *) malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < ls1)
		s[i] = s1[i];
	i = -1;
	while (++i < ls2)
		s[i + ls1] = s2[i];
	s[i + ls1] = '\0';
	return (s);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		size;

	size = ft_strlen(s);
	dup = (char *) malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start > len)
		size = len + 1;
	else
		size = slen - start + 1;
	sub = (char *) malloc(sizeof(char) * size);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1 && (s + start)[i] != '\0')
	{
		sub[i] = (s + start)[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
