/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:25:30 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/27 17:46:04 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	win_malloc(t_all *all)
{
	all->win = (t_win *)malloc(sizeof(t_win));
	if (!all->win)
		return (0);
	all->win->win = 0;
	all->win->mlx = 0;
	all->win->win_x = 0;
	all->win->win_y = 0;
	all->win->x_max = 0;
	all->win->y_max = 0;
	return (1);
}

int	img_malloc(t_all *all)
{
	all->img = (t_data *)malloc(sizeof(t_data));
	if (!all->img)
		return (0);
	all->img->addr = 0;
	all->img->bits_per_pixel = 0;
	all->img->endian = 0;
	all->img->img = 0;
	all->img->line_length = 0;
	return (1);
}

int	spr_malloc(t_all *all)
{
	all->spr = (t_sprite *)malloc(sizeof(t_sprite));
	if (!all->spr)
		return (0);
	all->spr->color = 0;
	all->spr->count = 0;
	all->spr->dr_end_x = 0;
	all->spr->dr_end_y = 0;
	all->spr->dr_sta_x = 0;
	all->spr->dr_sta_y = 0;
	all->spr->hei = 0;
	all->spr->inv_d = 0;
	all->spr->scr_x = 0;
	all->spr->trans_x = 0;
	all->spr->trans_y = 0;
	all->spr->width = 0;
	all->spr->x = 0;
	all->spr->y = 0;
	return (1);
}
