/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:20:16 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 15:37:01 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	mlx_win_img_addr(t_all *all)
{
	all->win->win = mlx_new_window(all->win->mlx, all->win->win_x,
			all->win->win_y, "cub3D");
	all->img->img = mlx_new_image(all->win->mlx, all->win->win_x,
			all->win->win_y);
	all->img->addr = mlx_get_data_addr(all->img->img,
			&all->img->bits_per_pixel, &all->img->line_length,
			&all->img->endian);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	int		offset;
	char	*dst;

	offset = y * all->img->line_length + x * (all->img->bits_per_pixel / 8);
	dst = all->img->addr + offset;
	*(unsigned int *)dst = color;
}

void	screen_drawing(t_all *all, int x)
{
	int		y;
	float	step;
	float	tex_p;

	step = 1.0 * all->tex->wall->heigt / all->draw->lineHeight;
	tex_p = (all->draw->drawStart - all->win->win_y / 2
			+ all->draw->lineHeight / 2) * step;
	y = -1;
	while (++y < all->draw->drawStart)
		my_mlx_pixel_put(all, x, y, all->c_color);
	y = all->draw->drawStart - 1;
	while (++y <= all->draw->drawEnd)
	{
		all->tex->tex_y = (int)tex_p & (all->tex->wall->heigt - 1);
		tex_p += step;
		all->tex->color = ((int *)(all->tex->wall->addr))[all->tex->wall->heigt
			* all->tex->tex_y + all->tex->tex_x];
		my_mlx_pixel_put(all, x, y, all->tex->color);
	}
	y = all->draw->drawEnd - 1;
	while (++y < all->win->win_y)
		my_mlx_pixel_put(all, x, y, all->f_color);
}

void	dir_x_and_y(t_all *all, float cameraX)
{
	all->ray->dir_x = all->plr->dir_x + all->plr->plane_x * cameraX;
	all->ray->dir_y = all->plr->dir_y + all->plr->plane_y * cameraX;
}

void	rays_throwing(t_all *all)
{
	float	cameraX;
	float	*buf;
	int		x;
	int		w;
	int		h;

	buf = malloc(sizeof(float) * all->win->win_x);
	if (!buf)
		return ;
	x = -1;
	w = all->win->win_x;
	h = all->win->win_y;
	while (++x < w)
	{
		cameraX = (2 * x) / (float)w - 1;
		dir_x_and_y(all, cameraX);
		pitch_length(all);
		ray_length(all);
		buf[x] = all->rays->perpWallDist;
		drawing_height(all, h);
		tex_create(all);
		screen_drawing(all, x);
	}
	add_spr(all, buf);
	free(buf);
}
