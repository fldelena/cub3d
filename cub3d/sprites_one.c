/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:30:18 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 16:07:18 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_lstclear_sec(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

void	sprite_one(t_all *all)
{
	all->spr->inv_d = 1.0 / (all->plr->plane_x * all->plr->dir_y
			- all->plr->dir_x * all->plr->plane_y);
	all->spr->trans_x = all->spr->inv_d * (all->plr->dir_y
			* all->spr->x - all->plr->dir_x * all->spr->y);
	all->spr->trans_y = all->spr->inv_d * (all->plr->plane_x
			* all->spr->y - all->plr->plane_y * all->spr->x);
	all->spr->scr_x = (int)((all->win->win_x / 2) * (1 + all->spr->trans_x
				/ all->spr->trans_y));
	all->spr->hei = (int)fabs(all->win->win_y / all->spr->trans_y);
	all->spr->dr_sta_y = -(all->spr->hei / 2) + (all->win->win_y / 2);
	if (all->spr->dr_sta_y < 0)
		all->spr->dr_sta_y = 0;
	all->spr->dr_end_y = (all->spr->hei / 2) + (all->win->win_y / 2);
	if (all->spr->dr_end_y >= all->win->win_y)
		all->spr->dr_end_y = all->win->win_y - 1;
	all->spr->width = (int)fabs(all->win->win_y / all->spr->trans_y);
	all->spr->dr_sta_x = -all->spr->width / 2 + all->spr->scr_x;
	if (all->spr->dr_sta_x < 0)
		all->spr->dr_sta_x = 0;
	all->spr->dr_end_x = all->spr->width / 2 + all->spr->scr_x;
	if (all->spr->dr_end_x >= all->win->win_x)
		all->spr->dr_end_x = all->win->win_x - 1;
}

void	sprite_two(t_all *all, float buf[])
{
	int		x;
	int		y;
	int		texX;

	x = all->spr->dr_sta_x;
	while (x < all->spr->dr_end_x)
	{
		texX = (int)(256 * (x - (all->spr->scr_x - all->spr->width / 2))
				* all->tex->wall->width / all->spr->width) / 256;
		if (all->spr->trans_y > 0 && x > 0 && x < all->win->win_x
			&& all->spr->trans_y < buf[x])
		{
			y = all->spr->dr_sta_y;
			while (y < all->spr->dr_end_y)
			{
				sprite_color(all, texX, x, y);
				y++;
			}
		}
		x++;
	}
}

void	free_spr(int *spr_o, float *spr_d, t_sprite *spt)
{
	free(spr_o);
	free(spr_d);
	free(spt);
}
