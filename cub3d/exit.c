/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:08:36 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 15:34:11 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	free_dda(t_all *all)
{
	if (all->plr)
		free(all->plr);
	if (all->draw)
		free(all->draw);
	if (all->rays)
		free(all->rays);
	if (all->ray)
		free(all->ray);
}

void	free_tex(t_all *all)
{
	if (all->tex->sprite)
		free(all->tex->sprite);
	if (all->tex->ea)
		free(all->tex->ea);
	if (all->tex->we)
		free(all->tex->we);
	if (all->tex->so)
		free(all->tex->so);
	if (all->tex->no)
		free(all->tex->no);
	if (all->tex->wall)
		free(all->tex->wall);
	if (all->tex)
		free(all->tex);
	if (all->spr)
		free(all->spr);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_all *all, int k)
{
	free(all->win->mlx);
	free(all->win->win);
	free(all->win);
	free_dda(all);
	if (k)
		free_tex(all);
	if (all->map)
		free_arr(all->map);
	if (all->img)
	{
		free(all->img);
	}
	free(all);
	exit(0);
}

void	exit_point(t_all *all, int i, int k)
{
	print_error(i);
	free_all(all, k);
}
