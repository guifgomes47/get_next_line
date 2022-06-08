/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:39:03 by guilhfer          #+#    #+#             */
/*   Updated: 2022/06/08 12:59:39 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_rest(char *buffer)
{
	int		i;
	int		size;
	int		rest_len;
	char	*rest;

	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (!buffer[size])
		return (free(buffer), NULL);
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
	return (rest);
}

char	*get_line(char *line)
{
	int		i;
	int		size;
	char	*format;

	size = 0;
	if (!line[size])
		return (NULL);
	while (line[size] && line[size] != '\n')
		size++;
	format = (char *)malloc(size + 2);
	if (!format)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
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
			return (free(find_nl), NULL);
		}
		if (read_bytes == 0)
		{
			free(find_nl);
			break ;
		}
		find_nl[read_bytes] = '\0';
		line = ft_strjoin(line, find_nl);
		free(find_nl);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest[4096];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rest[fd] = read_file(rest[fd], fd);
	line = get_line(rest[fd]);
	rest[fd] = get_rest(rest[fd]);
	return (line);
}
