/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:13:07 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/30 18:15:43 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

t_flag	*flag_malloc(void)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	flag->no = 0;
	flag->so = 0;
	flag->we = 0;
	flag->ea = 0;
	flag->r = 0;
	flag->f = 0;
	flag->c = 0;
	flag->s = 0;
	return (flag);
}

int	get_r(t_all *all, char *line)
{
	char	**r_param;

	all->f->r++;
	r_param = ft_split(line, ' ');
	if (!r_param[2] || r_param[3])
		exit_point(all, 1, 1);
	if (nothing_extra(r_param[1]) || nothing_extra(r_param[2]))
		exit_point(all, 4, 1);
	win_size(all, r_param[1], r_param[2]);
	free_arr(r_param);
	return (0);
}

void	get_color_f_or_c(t_all *all, char *line, char f_or_c)
{
	char	**col_p;
	int		col;

	if (ft_simbcount(line, ',') != 2)
		exit_point(all, 4, 1);
	col_p = ft_split(line, ',');
	col_p[0] = ft_strtrim(col_p[0], " ");
	col_p[1] = ft_strtrim(col_p[1], " ");
	col_p[2] = ft_strtrim(col_p[2], " ");
	if (nothing_extra(col_p[0]) || nothing_extra(col_p[1])
		|| nothing_extra(col_p[2]))
		exit_point(all, 4, 1);
	col = col_rgb(all, ft_atoi(col_p[0]), ft_atoi(col_p[1]), ft_atoi(col_p[2]));
	free_arr(col_p);
	if (f_or_c == 'f')
	{
		all->f_color = col;
		all->f->f++;
	}
	else if (f_or_c == 'c')
	{
		all->c_color = col;
		all->f->c++;
	}
}

void	get_path(t_all *all, char **arr, char nswes)
{
	if (nswes == 'N')
	{
		all->tex->no->path = ft_strdup(arr[1]);
		all->f->no++;
	}
	else if (nswes == 'S')
	{
		all->tex->so->path = ft_strdup(arr[1]);
		all->f->so++;
	}
	else if (nswes == 'W')
	{
		all->tex->we->path = ft_strdup(arr[1]);
		all->f->we++;
	}
	else if (nswes == 'E')
	{
		all->tex->ea->path = ft_strdup(arr[1]);
		all->f->ea++;
	}
	else if (nswes == 's')
	{
		all->tex->sprite->path = ft_strdup(arr[1]);
		all->f->s++;
	}
}

int	get_tex_path(t_all *all, char *line, char nswes)
{
	char	**arr;

	arr = ft_split(line, ' ');
	get_path(all, arr, nswes);
	free_arr(arr);
	return (0);
}
