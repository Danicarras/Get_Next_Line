/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarras <dacarras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:53:49 by dacarras          #+#    #+#             */
/*   Updated: 2025/02/10 18:05:27 by dacarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*endstr;
	size_t		totlen;
	int			i;
	int			j;

	totlen = ft_strlen(s1) + ft_strlen(s2);
	endstr = ft_calloc(sizeof(char), (totlen + 1));
	if (!endstr)
	{
		free(endstr);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		endstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		endstr[i++] = s2[j++];
	free(s1);
	return (endstr);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*p;
	size_t		i;
	size_t		n;

	n = size * nmemb;
	p = (char *) malloc(n);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
