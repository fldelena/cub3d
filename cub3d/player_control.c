/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:32:25 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/29 22:24:27 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	turn_right(t_all *all, float rootSpeed)
{
	float	oldDirX;
	float	oldPlaneX;

	oldDirX = all->plr->dir_x;
	all->plr->dir_x = all->plr->dir_x * cos(rootSpeed) - all->plr->dir_y
		* sin(rootSpeed);
	all->plr->dir_y = oldDirX * sin(rootSpeed) + all->plr->dir_y
		* cos(rootSpeed);
	oldPlaneX = all->plr->plane_x;
	all->plr->plane_x = all->plr->plane_x * cos(rootSpeed) - all->plr->plane_y
		* sin(rootSpeed);
	all->plr->plane_y = oldPlaneX * sin(rootSpeed) + all->plr->plane_y
		* cos(rootSpeed);
}

void	turn_left(t_all *all, float rootSpeed)
{
	float	oldDirX;
	float	oldPlaneX;

	oldDirX = all->plr->dir_x;
	all->plr->dir_x = all->plr->dir_x * cos(-rootSpeed) - all->plr->dir_y
		* sin(-rootSpeed);
	all->plr->dir_y = oldDirX * sin(-rootSpeed) + all->plr->dir_y
		* cos(-rootSpeed);
	oldPlaneX = all->plr->plane_x;
	all->plr->plane_x = all->plr->plane_x * cos(-rootSpeed) - all->plr->plane_y
		* sin(-rootSpeed);
	all->plr->plane_y = oldPlaneX * sin(-rootSpeed) + all->plr->plane_y
		* cos(-rootSpeed);
}

int	move(int keycode, t_all *all)
{
	float	moveSpeed;
	float	rootSpeed;

	moveSpeed = 0.1;
	rootSpeed = 0.1;
	if (keycode == 13)
		move_forward(all, moveSpeed);
	if (keycode == 1)
		move_back(all, moveSpeed);
	if (keycode == 2)
		move_right(all, moveSpeed);
	if (keycode == 0)
		move_left(all, moveSpeed);
	if (keycode == 123)
		turn_left(all, rootSpeed);
	if (keycode == 124)
		turn_right(all, rootSpeed);
	return (0);
}
