/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarras <dacarras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:53:52 by dacarras          #+#    #+#             */
/*   Updated: 2025/02/10 18:10:50 by dacarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *storage)
{
	char	*buff;
	int		dim;

	buff = ft_calloc((sizeof(char)), (BUFFER_SIZE + 1));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	dim = 1;
	while (!(ft_strchr(storage, '\n')) && dim != 0)
	{
		dim = read(fd, buff, BUFFER_SIZE);
		if (dim < 0)
		{
			free(buff);
			free(storage);
			return (NULL);
		}
		buff[dim] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

static char	*save_extra(char *storage)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	buff = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	j = 0;
	i++;
	while (storage[i])
		buff[j++] = storage[i++];
	buff[j] = '\0';
	free(storage);
	return (buff);
}

static char	*save_line(char *storage)
{
	char	*buff;
	int		i;
	int		j;

	if (storage[0] == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	buff = ft_calloc((sizeof(char *)), (i + 1));
	if (!buff)
		return (NULL);
	while (j <= i)
	{
		buff[j] = storage[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_line(fd, storage);
	if (!storage)
		return (NULL);
	line = save_line(storage);
	storage = save_extra(storage);
	return (line);
}

/* int main()
{
	int fd = open("empty.txt", O_RDONLY);
	char *r;
	r = get_next_line(fd);
	while (r)
	{
		free(r);
		r = get_next_line(fd);
		printf("%s", r);

	}
	close(fd);
	return 0;
}  */