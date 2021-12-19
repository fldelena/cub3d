/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:40:54 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/28 13:41:44 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	buffer_null(char *buf, char *buffer)
{
	int	i;

	i = 0;
	while (i < 14)
		buf[i++] = (unsigned char)(0);
	i = 0;
	while (i < 40)
		buffer[i++] = (unsigned char)(0);
}

void	int_to_char(int i, char *buf)
{
	buf[0] = i % 256;
	buf[1] = i / 256 % 256;
	buf[2] = i / 256 / 256 % 256;
	buf[3] = i / 256 / 256 / 256;
}
