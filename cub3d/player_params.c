/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:21:01 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/29 22:33:45 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	player_pos_N(t_all *all, int i, int j)
{
	all->plr->p_x = j + 0.5;
	all->plr->p_y = i + 0.5;
	all->plr->dir_x = 0.0;
	all->plr->dir_y = -1.0;
	all->plr->plane_x = 0.66;
	all->plr->plane_y = 0.0;
	all->map[i][j] = '0';
}

void	player_pos_E(t_all *all, int i, int j)
{
	all->plr->p_x = j + 0.5;
	all->plr->p_y = i + 0.5;
	all->plr->dir_x = 1.0;
	all->plr->dir_y = 0.0;
	all->plr->plane_x = 0.0;
	all->plr->plane_y = 0.66;
	all->map[i][j] = '0';
}

void	player_pos_S(t_all *all, int i, int j)
{
	all->plr->p_x = j + 0.5;
	all->plr->p_y = i + 0.5;
	all->plr->dir_x = 0.0;
	all->plr->dir_y = 1.0;
	all->plr->plane_x = -0.66;
	all->plr->plane_y = 0.0;
	all->map[i][j] = '0';
}

void	player_pos_W(t_all *all, int i, int j)
{
	all->plr->p_x = j + 0.5;
	all->plr->p_y = i + 0.5;
	all->plr->dir_x = -1.0;
	all->plr->dir_y = 0.0;
	all->plr->plane_x = 0.0;
	all->plr->plane_y = -0.66;
	all->map[i][j] = '0';
}

void	player_position(t_all *all)
{
	int	i;
	int	j;

	i = 7;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == 'N')
				player_pos_N(all, i, j);
			else if (all->map[i][j] == 'E')
				player_pos_E(all, i, j);
			else if (all->map[i][j] == 'S')
				player_pos_S(all, i, j);
			else if (all->map[i][j] == 'W')
				player_pos_W(all, i, j);
		}
	}
}
