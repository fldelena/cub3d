/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:19:46 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/30 18:13:14 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	buffer_set(t_all *all, char *buffer, int fd)
{
	int	n;

	buffer[0] = '(';
	n = all->win->win_x;
	int_to_char(n, buffer + 4);
	n = all->win->win_y;
	int_to_char(n, buffer + 8);
	buffer[12] = 1;
	buffer[14] = ' ';
	write(fd, buffer, 40);
}

void	set_pixels(t_all *all, int fd)
{
	int				i;
	int				j;
	unsigned char	buf[4];

	i = all->win->win_x * (all->win->win_y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < all->win->win_x)
		{
			buf[0] = (((int *)(all->img->addr))[i] % 256);
			buf[1] = (((int *)(all->img->addr))[i] / 256 % 256);
			buf[2] = (((int *)(all->img->addr))[i] / 256 / 256 % 256);
			buf[3] = 0;
			write(fd, buf, 4);
			i++;
			j++;
		}
		i -= 2 * all->win->win_x;
	}
}

void	image(t_all *all, int fd)
{
	all->img->img = mlx_new_image(all->win->mlx, all->win->win_x,
			all->win->win_y);
	all->img->addr = mlx_get_data_addr(all->img->img,
			&all->img->bits_per_pixel, &all->img->line_length,
			&all->img->endian);
	rays_throwing(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->img->img, 0, 0);
	set_pixels(all, fd);
	mlx_destroy_image(all->win->mlx, all->img->img);
}

int	save_bmp(t_all *all)
{
	char	buf[14];
	char	buffer[40];
	int		fd;
	int		size;

	render_next_frame(all);
	size = all->win->win_x * all->win->win_y * 4 + 54;
	buffer_null(buf, buffer);
	fd = open("screen_cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		printf("Error\nProblem width make screen\n");
		free_all(all, 0);
	}
	buf[0] = 'B';
	buf[1] = 'M';
	int_to_char(size, buf + 2);
	buf[10] = '6';
	write(fd, buf, 14);
	buffer_set(all, buffer, fd);
	image(all, fd);
	close(fd);
	free_all(all, 0);
	return (0);
}
