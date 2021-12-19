/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:18:05 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/29 22:20:03 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	move_forward(t_all *all, float moveSpeed)
{
	if ((all->map[(int)all->plr->p_y][(int)(all->plr->p_x + all->plr->dir_x
			* moveSpeed)]) != '1')
		all->plr->p_x += all->plr->dir_x * moveSpeed;
	if ((all->map[(int)(all->plr->p_y + all->plr->dir_y
				* moveSpeed)][(int)all->plr->p_x]) != '1')
		all->plr->p_y += all->plr->dir_y * moveSpeed;
}

void	move_right(t_all *all, float moveSpeed)
{
	if ((all->map[(int)all->plr->p_y][(int)(all->plr->p_x + all->plr->plane_x
			* moveSpeed)]) != '1')
		all->plr->p_x += all->plr->plane_x * moveSpeed;
	if ((all->map[(int)(all->plr->p_y + all->plr->plane_y
				* moveSpeed)][(int) all->plr->p_x]) != '1')
		all->plr->p_y += all->plr->plane_y * moveSpeed;
}

void	move_back(t_all *all, float moveSpeed)
{
	if ((all->map[(int)all->plr->p_y][(int)(all->plr->p_x - all->plr->dir_x
			* moveSpeed)]) != '1')
		all->plr->p_x -= all->plr->dir_x * moveSpeed;
	if ((all->map[(int)(all->plr->p_y - all->plr->dir_y
				* moveSpeed)][(int) all->plr->p_x]) != '1')
		all->plr->p_y -= all->plr->dir_y * moveSpeed;
}

void	move_left(t_all *all, float moveSpeed)
{
	if ((all->map[(int)all->plr->p_y][(int)(all->plr->p_x - all->plr->plane_x
			* moveSpeed)]) != '1')
		all->plr->p_x -= all->plr->plane_x * moveSpeed;
	if ((all->map[(int)(all->plr->p_y - all->plr->plane_y
				* moveSpeed)][(int) all->plr->p_x]) != '1')
		all->plr->p_y -= all->plr->plane_y * moveSpeed;
}
