/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guifgomes <guifgomes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:48:12 by guifgomes         #+#    #+#             */
/*   Updated: 2022/05/24 13:10:52 by guifgomes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	void	*buf;
	size_t	nbytes;

}

int	main(void)
{
	int			fd;
	char		buffer[80];
	const char	*ptr;

	ptr = "test.txt";
	fd = open(ptr, O_RDWR);
	printf("fd = %d\n", fd);
	if (fd == -1)
	{
		printf("Failed to create and open the file.\n");
	}
	close(fd);
}
