/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:48:12 by guifgomes         #+#    #+#             */
/*   Updated: 2022/05/30 12:15:03 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



char	*get_next_line(int fd)
{
	char	*acc;
	char	*str;
	int		read_bytes;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	read_bytes = read(fd, str, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		printf("%s", str);
		read_bytes = read(fd, str, BUFFER_SIZE);
		str[read_bytes] = '\0';
	}
	return (str);
}
