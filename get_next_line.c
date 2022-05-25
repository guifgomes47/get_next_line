/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guifgomes <guifgomes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:48:12 by guifgomes         #+#    #+#             */
/*   Updated: 2022/05/25 16:55:04 by guifgomes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		current_buffer;
	static char	*accumulator;

	current_buffer = 1;
	if (!accumulator)
	{
		(char *)malloc(sizeof(char) * ft_strlen(accumulator));
	}
}
