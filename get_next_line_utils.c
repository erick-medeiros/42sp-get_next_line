/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 03:43:33 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/23 18:53:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	ls1 = (size_t)(ft_strchr(s1, '\0') - s1);
	ls2 = (size_t)(ft_strchr(s2, '\0') - s2);
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

	size = (int)(ft_strchr(s, '\0') - s);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = (size_t)(ft_strchr(src, '\0') - src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	size;

	if (s == NULL)
		return (NULL);
	slen = (size_t)(ft_strchr(s, '\0') - s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start > len)
		size = len + 1;
	else
		size = slen - start + 1;
	sub = (char *) malloc(sizeof(char) * size);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, (s + start), size);
	return (sub);
}
