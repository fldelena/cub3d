/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:00:10 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 16:27:47 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilib/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_draw
{
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
}				t_draw;

typedef struct s_dist
{
	float			s_dist_x;
	float			s_dist_y;
	float			d_dist_x;
	float			d_dist_y;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	float			perpWallDist;
}				t_dist;

typedef struct s_win //структура для окна
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				x_max;
	int				y_max;
}				t_win;

typedef struct s_plr //структура для игрока и луча
{
	float			p_x;
	float			p_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
}				t_plr;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

typedef struct s_texxpm
{
	char			*path;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				heigt;
}				t_texxpm;

typedef struct s_tex
{
	t_texxpm		*no;
	t_texxpm		*so;
	t_texxpm		*we;
	t_texxpm		*ea;
	t_texxpm		*wall;
	t_texxpm		*sprite;
	int				color;
	int				tex_w;
	int				tex_h;
	int				tex_y;
	int				tex_x;
}				t_tex;

typedef struct s_pair
{
	float			f;
	int				sec;
}				t_pair;

typedef struct s_sprite
{
	float			x;
	float			y;
	float			inv_d;
	float			trans_x;
	float			trans_y;
	int				scr_x;
	int				hei;
	int				dr_sta_y;
	int				dr_end_y;
	int				dr_sta_x;
	int				dr_end_x;
	int				width;
	int				count;
	int				color;
}				t_sprite;

typedef struct s_flag
{
	int				r;
	int				f;
	int				c;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
}				t_flag;

typedef struct s_all
{
	t_win			*win;
	t_data			*img;
	t_plr			*plr;
	t_plr			*ray;
	t_dist			*rays;
	t_draw			*draw;
	t_tex			*tex;
	t_sprite		*spr;
	t_flag			*f;
	int				f_color;
	int				c_color;
	char			**map;
}				t_all;

int		win_malloc(t_all *all);
int		img_malloc(t_all *all);
int		spr_malloc(t_all *all);
int		dda_malloc(t_all *all);
int		tex_malloc(t_all *all);
void	free_all(t_all *all, int k);
int		parcer(int argc, char **argv, t_all *all);
int		get_r(t_all *all, char *line);
void	win_size(t_all *all, char *x, char *y);
void	get_color_f_or_c(t_all *all, char *line, char f_or_c);
int		get_tex_path(t_all *all, char *line, char nswe);
int		col_rgb(t_all *all, int r, int g, int b);
void	player_position(t_all *all);
int		save_bmp(t_all *all);
void	move_forward(t_all *all, float moveSpeed);
void	move_right(t_all *all, float moveSpeed);
void	move_back(t_all *all, float moveSpeed);
void	move_left(t_all *all, float moveSpeed);
int		move(int keycode, t_all *all);
int		render_next_frame(t_all *all);
void	rays_throwing(t_all *all);
void	pitch_length(t_all *all);
void	ray_length(t_all *all);
void	drawing_height(t_all *all, int h);
void	tex_create(t_all *all);
void	get_tex_data_addr(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
void	add_spr(t_all *all, float buf[]);
void	exit_point(t_all *all, int i, int k);
t_flag	*flag_malloc(void);
void	is_map_symbol(t_all *all, char c);
int		nothing_extra(char *str);
void	buffer_null(char *buf, char *buffer);
void	int_to_char(int i, char *buf);
void	print_error(int i);
void	sprite_color(t_all *all, int texX, int x, int y);
void	sprite_one(t_all *all);
void	sprite_two(t_all *all, float buf[]);
void	free_arr(char **arr);
void	check_params(t_all *all, int player);
void	check_map(t_all *all, char *line);
int		ft_flood(char **map, int k, int j);
void	mlx_win_img_addr(t_all *all);
void	ft_lstclear_sec(t_list **lst);
void	free_spr(int *spr_o, float *spr_d, t_sprite *spt);

#endif
