/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:24:07 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 16:10:03 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	sprite_list(t_all *all, t_sprite spt[], int spr_o[], float spr_d[])
{
	int	i;
	int	j;
	int	c;

	i = 7;
	c = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
			{
				spt[++c].x = j + 0.5;
				spt[c].y = i +0.5;
			}
		}
	}
	c = -1;
	while (++c < all->spr->count)
	{
		spr_o[c] = c;
		spr_d[c] = ((all->plr->p_x - spt[c].x) * (all->plr->p_x - spt[c].x)
				+ (all->plr->p_y - spt[c].y) * (all->plr->p_y - spt[c].y));
	}
}

void	sort_order(t_pair *spr, int sprcount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < sprcount)
	{
		j = -1;
		while (++j < sprcount - 1)
		{
			if (spr[j].f > spr[j + 1].f)
			{
				tmp.f = spr[j].f;
				tmp.sec = spr[j].sec;
				spr[j].f = spr[j + 1].f;
				spr[j].sec = spr[j + 1].sec;
				spr[j + 1].f = tmp.f;
				spr[j + 1].sec = tmp.sec;
			}
		}
	}
}

void	sprite_sort(int *spr_o, float *spr_d, int sprcount)
{
	t_pair	*spr;
	int		i;

	i = -1;
	spr = (t_pair *)malloc(sizeof(t_pair) * sprcount);
	if (!spr)
		return ;
	while (++i < sprcount)
	{
		spr[i].f = spr_d[i];
		spr[i].sec = spr_o[i];
	}
	sort_order(spr, sprcount);
	i = -1;
	while (++i < sprcount)
	{
		spr_d[i] = spr[sprcount - i - 1].f;
		spr_o[i] = spr[sprcount - i - 1].sec;
	}
	free(spr);
}

void	sprite_color(t_all *all, int texX, int x, int y)
{
	int		d;
	int		texY;

	d = y * 256 - all->win->win_y * 128 + all->spr->hei * 128;
	texY = d * all->tex->wall->heigt / all->spr->hei / 256;
	all->spr->color = ((int *)all->tex->sprite->addr)[all->tex->sprite->width
		* texY + texX];
	if (all->spr->color != 0)
		my_mlx_pixel_put(all, x, y, all->spr->color);
}

void	add_spr(t_all *all, float buf[])
{
	int			*spr_o;
	float		*spr_d;
	t_sprite	*spt;
	int			i;

	spr_o = malloc(sizeof(int) * all->spr->count);
	if (!spr_o)
		return ;
	spr_d = malloc(sizeof(float) * all->spr->count);
	if (!spr_d)
		return ;
	spt = malloc(sizeof(t_sprite) * all->spr->count);
	if (!spt)
		return ;
	sprite_list(all, spt, spr_o, spr_d);
	sprite_sort(spr_o, spr_d, all->spr->count);
	i = -1;
	while (++i < all->spr->count)
	{
		all->spr->x = spt[spr_o[i]].x - all->plr->p_x;
		all->spr->y = spt[spr_o[i]].y - all->plr->p_y;
		sprite_one(all);
		sprite_two(all, buf);
	}
	free_spr(spr_o, spr_d, spt);
}
