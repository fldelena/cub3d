/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:42:40 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/30 18:17:00 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./includes/cub3d.h"

int	tex_malloc(t_all *all)
{
	all->tex = (t_tex *)malloc(sizeof(t_tex));
	if (!(all->tex))
		return (0);
	all->tex->no = malloc(sizeof(t_texxpm));
	if (!(all->tex->no))
		return (0);
	all->tex->so = malloc(sizeof(t_texxpm));
	if (!(all->tex->so))
		return (0);
	all->tex->we = malloc(sizeof(t_texxpm));
	if (!(all->tex->we))
		return (0);
	all->tex->ea = malloc(sizeof(t_texxpm));
	if (!(all->tex->ea))
		return (0);
	all->tex->wall = 0;
	all->tex->sprite = malloc(sizeof(t_texxpm));
	if (!(all->tex->sprite))
		return (0);
	return (1);
}

void	texture_path(t_all *all)
{
	all->tex->no->img = mlx_xpm_file_to_image(all->win->mlx,
			all->tex->no->path, &all->tex->no->width, &all->tex->no->heigt);
	if (all->tex->no->img == 0)
		exit_point(all, 8, 1);
	all->tex->so->img = mlx_xpm_file_to_image(all->win->mlx,
			all->tex->so->path, &all->tex->so->width, &all->tex->so->heigt);
	if (all->tex->so->img == 0)
		exit_point(all, 8, 1);
	all->tex->we->img = mlx_xpm_file_to_image(all->win->mlx,
			all->tex->we->path, &all->tex->we->width, &all->tex->we->heigt);
	if (all->tex->we->img == 0)
		exit_point(all, 8, 1);
	all->tex->ea->img = mlx_xpm_file_to_image(all->win->mlx,
			all->tex->ea->path, &all->tex->ea->width, &all->tex->ea->heigt);
	if (all->tex->ea->img == 0)
		exit_point(all, 8, 1);
	all->tex->sprite->img = mlx_xpm_file_to_image(all->win->mlx,
			all->tex->sprite->path, &all->tex->sprite->width,
			&all->tex->sprite->heigt);
	if (all->tex->sprite->img == 0)
		exit_point(all, 8, 1);
}

void	get_tex_data_addr(t_all *all)
{
	texture_path(all);
	all->tex->no->addr = mlx_get_data_addr(all->tex->no->img,
			&all->tex->no->bits_per_pixel, &all->tex->no->line_length,
			&all->tex->no->endian);
	all->tex->so->addr = mlx_get_data_addr(all->tex->so->img,
			&all->tex->so->bits_per_pixel, &all->tex->so->line_length,
			&all->tex->so->endian);
	all->tex->we->addr = mlx_get_data_addr(all->tex->we->img,
			&all->tex->we->bits_per_pixel, &all->tex->we->line_length,
			&all->tex->we->endian);
	all->tex->ea->addr = mlx_get_data_addr(all->tex->ea->img,
			&all->tex->ea->bits_per_pixel, &all->tex->ea->line_length,
			&all->tex->ea->endian);
	all->tex->sprite->addr = mlx_get_data_addr(all->tex->sprite->img,
			&all->tex->sprite->bits_per_pixel,
			&all->tex->sprite->line_length, &all->tex->sprite->endian);
}

void	wall_side(t_all *all)
{
	if (all->rays->side == 0 && all->rays->step_x < 0)
		all->tex->wall = all->tex->we;
	if (all->rays->side == 0 && all->rays->step_x > 0)
		all->tex->wall = all->tex->ea;
	if (all->rays->side == 1 && all->rays->step_y < 0)
		all->tex->wall = all->tex->no;
	if (all->rays->side == 1 && all->rays->step_y > 0)
		all->tex->wall = all->tex->so;
}

void	tex_create(t_all *all)
{
	float	wall_x;

	if (all->rays->side == 0)
		wall_x = all->plr->p_y + all->rays->perpWallDist * all->ray->dir_y;
	else
		wall_x = all->plr->p_x + all->rays->perpWallDist * all->ray->dir_x;
	wall_x -= floor((wall_x));
	wall_side(all);
	all->tex->tex_x = (int)(wall_x * (float)all->tex->wall->width);
	if (all->rays->side == 0 && all->ray->dir_x > 0)
		all->tex->tex_x = all->tex->wall->width - all->tex->tex_x - 1;
	if (all->rays->side == 1 && all->ray->dir_x < 0)
		all->tex->tex_x = all->tex->wall->width - all->tex->tex_x - 1;
}
