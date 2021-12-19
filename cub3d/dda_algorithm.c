/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:30:57 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/30 21:43:59 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	dda_malloc(t_all *all)
{
	all->plr = (t_plr *)malloc(sizeof(t_plr));
	if (!all->plr)
		return (0);
	all->ray = (t_plr *)malloc(sizeof(t_plr));
	if (!all->ray)
		return (0);
	all->rays = (t_dist *)malloc(sizeof(t_dist));
	if (!all->rays)
		return (0);
	all->draw = (t_draw *)malloc(sizeof(t_draw));
	if (!all->draw)
		return (0);
	return (1);
}

void	spacing(t_all *all)
{
	if (all->ray->dir_x < 0)
	{
		all->rays->step_x = -1;
		all->rays->s_dist_x = (all->plr->p_x - all->rays->map_x)
			* all->rays->d_dist_x;
	}
	else
	{
		all->rays->step_x = 1;
		all->rays->s_dist_x = (all->rays->map_x + 1.0 - all->plr->p_x)
			* all->rays->d_dist_x;
	}
	if (all->ray->dir_y < 0)
	{
		all->rays->step_y = -1;
		all->rays->s_dist_y = (all->plr->p_y - all->rays->map_y)
			* all->rays->d_dist_y;
	}
	else
	{
		all->rays->step_y = 1;
		all->rays->s_dist_y = (all->rays->map_y + 1.0 - all->plr->p_y)
			* all->rays->d_dist_y;
	}
}

void	pitch_length(t_all *all)
{
	all->rays->map_x = (int) all->plr->p_x;
	all->rays->map_y = (int) all->plr->p_y;
	all->rays->hit = 0;
	all->rays->side = 0;
	if (all->ray->dir_y == 0)
		all->rays->d_dist_x = 0;
	else
	{
		if (all->ray->dir_x == 0)
			all->rays->d_dist_x = 1;
		else
			all->rays->d_dist_x = fabs(1 / all->ray->dir_x);
	}
	if (all->ray->dir_x == 0)
		all->rays->d_dist_y = 0;
	else
	{
		if (all->ray->dir_y == 0)
			all->rays->d_dist_y = 1;
		else
			all->rays->d_dist_y = fabs(1 / all->ray->dir_y);
	}
	spacing(all);
}

void	ray_length(t_all *all)
{
	while (all->rays->hit == 0)
	{
		if (all->rays->s_dist_x < all->rays->s_dist_y)
		{
			all->rays->s_dist_x += all->rays->d_dist_x;
			all->rays->map_x += all->rays->step_x;
			all->rays->side = 0;
		}
		else
		{
			all->rays->s_dist_y += all->rays->d_dist_y;
			all->rays->map_y += all->rays->step_y;
			all->rays->side = 1;
		}
		if (all->map[all->rays->map_y][all->rays->map_x] == '1')
			all->rays->hit = 1;
	}
	if (all->rays->side == 0)
		all->rays->perpWallDist = (all->rays->map_x - all->plr->p_x
				+ (1 - all->rays->step_x) / 2) / all->ray->dir_x;
	else
		all->rays->perpWallDist = (all->rays->map_y - all->plr->p_y
				+ (1 - all->rays->step_y) / 2) / all->ray->dir_y;
}

void	drawing_height(t_all *all, int h)
{
	all->draw->lineHeight = (int)(h / all->rays->perpWallDist);
	all->draw->drawStart = (-all->draw->lineHeight / 2 + (h / 2));
	if (all->draw->drawStart < 0)
		all->draw->drawStart = 0;
	all->draw->drawEnd = (all->draw->lineHeight / 2 + (h / 2));
	if (all->draw->drawEnd >= h)
		all->draw->drawEnd = h - 1;
}
