/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:45:29 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 15:32:56 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

t_all	*all_malloc(void)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (0);
	all->map = 0;
	if (win_malloc(all) == 0)
		return (0);
	if (img_malloc(all) == 0)
		return (0);
	if (dda_malloc(all) == 0)
		return (0);
	if (tex_malloc(all) == 0)
		return (0);
	if (spr_malloc(all) == 0)
		return (0);
	all->f = flag_malloc();
	all->c_color = 0;
	all->f_color = 0;
	return (all);
}

int	key_hook(int keycode, t_all *all)
{
	move(keycode, all);
	if (keycode == 53)
	{
		mlx_destroy_window(all->win->mlx, all->win->win);
		exit (0);
	}
	return (0);
}

int	krestik(t_all *all)
{
	free_all(all, 0);
	return (0);
}

int	render_next_frame(t_all *all)
{
	rays_throwing(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->img->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = all_malloc();
	if (all == 0)
		free_all(all, 1);
	all->win->mlx = mlx_init();
	parcer(argc, argv, all);
	player_position(all);
	ft_flood(all->map, all->plr->p_x, all->plr->p_y);
	get_tex_data_addr(all);
	mlx_win_img_addr(all);
	if (argc == 3 && ft_strnstr(argv[2], "--save", 6)
		&& ft_strlen(argv[2]) == 6)
		return (save_bmp(all));
	else if (argc == 3)
		exit_point(all, 7, 1);
	mlx_hook(all->win->win, 2, 0, key_hook, all);
	mlx_hook(all->win->win, 17, 0l, &krestik, all);
	mlx_loop_hook(all->win->mlx, render_next_frame, all);
	mlx_loop(all->win->mlx);
	free_all(all, 1);
}

//-fsanitize=address
