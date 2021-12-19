/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_tools_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:44:50 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 18:19:35 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	nothing_extra(char *str)
{
	int	j;

	j = -1;
	while (str[++j])
	{
		if (!ft_isdigit(str[j]))
			return (1);
	}
	return (0);
}

void	win_size(t_all *all, char *x, char *y)
{
	mlx_get_screen_size(&all->win->x_max, &all->win->y_max);
	all->win->win_x = ft_atoi(x);
	all->win->win_y = ft_atoi(y);
	if (all->win->win_x < 0 || all->win->win_y < 0)
		exit_point(all, 4, 1);
	if (all->win->win_x < 320)
		all->win->win_x = 320;
	else if (all->win->win_x > all->win->x_max)
		all->win->win_x = all->win->x_max;
	if (all->win->win_y < 240)
		all->win->win_y = 240;
	else if (all->win->win_y > all->win->y_max)
		all->win->win_y = all->win->y_max;
}

int	col_rgb(t_all *all, int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_point(all, 4, 1);
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	check_map(t_all *all, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != ' ' && line[i] != '2')
			exit_point(all, 2, 1);
	}
}

void	check_params(t_all *all, int player)
{
	if (all->f->r + all->f->f + all->f->c + all->f-> no + all->f->so
		+ all->f->we + all->f->ea + all->f->s != 8)
		exit_point(all, 4, 1);
	if (player != 1)
		exit_point(all, 6, 1);
}
