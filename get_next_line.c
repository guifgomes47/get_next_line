/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:39:03 by guilhfer          #+#    #+#             */
/*   Updated: 2022/06/02 15:48:21 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_rest(char *buffer)
{
	int		i;
	int		size;
	int		rest_len;
	char	*rest;

	size = ft_strchr(buffer, '\n') - buffer;
	if (buffer[size] == '\n')
		size++;
	rest_len = ft_strlen(buffer) - size;
	rest = (char *)malloc(rest_len + 1);
	if (!rest)
		return (NULL);
	i = 0;
	while (buffer[size])
		rest[i++] = buffer[size++];
	rest[i] = '\0';
	free(buffer);
	free(rest);
	return (rest);
}

char	*get_line(char *line)
{
	int		size;
	int		i;
	char	*format;

	size = ft_strchr(line, '\n') - line;
	format = (char *)malloc(size + 2);
	if (!format)
		return (NULL);
	i = 0;
	while (i < size)
	{
		format[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		format[i++] = '\n';
	format[i] = '\0';
	return (format);
}

char	*read_file(char *line, int fd)
{
	char	*find_nl;
	int		read_bytes;

	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line, '\n'))
	{
		find_nl = (char *)malloc(BUFFER_SIZE + 1);
		if (!find_nl)
			return (NULL);
		read_bytes = read(fd, find_nl, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(find_nl);
			return (NULL);
		}
		if (read_bytes == 0)
		{
			free(find_nl);
			break ;
		}
		find_nl[read_bytes] = '\0';
		line = ft_strjoin(line, find_nl);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	rest = read_file(rest, fd);
	line = get_line(rest);
	rest = get_rest(rest);
	return (line);
}
