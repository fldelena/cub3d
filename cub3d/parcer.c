/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:19:55 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 15:54:07 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

char	**make_map(t_all *all, t_list **head, int size)
{
	t_list	*tmp;
	int		i;

	all->map = ft_calloc(size + 1, sizeof(char *));
	tmp = *head;
	i = -1;
	while (tmp)
	{
		all->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	i = -1;
	while (all->map[++i])
	{
		ft_putendl(all->map[i]);
	}
	ft_lstclear_sec(head);
	return (all->map);
}

void	map_reading(char **argv, t_all *all)
{
	t_list	*head;
	char	*line;
	int		fd;

	head = NULL ;
	line = NULL ;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_point(all, 3, 1);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(all, &head, ft_lstsize(head));
}

int	config_reader(t_all *all, char *line)
{
	line += ft_trim(line);
	if (ft_strnstr(line, "R ", 2) && all->f->r == 0)
		get_r(all, line);
	else if (ft_strnstr(line, "F ", 2) && all->f->f == 0)
		get_color_f_or_c(all, line + 2, 'f');
	else if (ft_strnstr(line, "C ", 2) && all->f->c == 0)
		get_color_f_or_c(all, line + 2, 'c');
	else if (ft_strnstr(line, "NO ", 3) && all->f->no == 0)
		get_tex_path(all, line, 'N');
	else if (ft_strnstr(line, "SO ", 3) && all->f->so == 0)
		get_tex_path(all, line, 'S');
	else if (ft_strnstr(line, "WE ", 3) && all->f->we == 0)
		get_tex_path(all, line, 'W');
	else if (ft_strnstr(line, "EA ", 3) && all->f->ea == 0)
		get_tex_path(all, line, 'E');
	else if (ft_strnstr(line, "S ", 2) && all->f->s == 0)
		get_tex_path(all, line, 's');
	if (all->f->r + all->f->f + all->f->c + all->f-> no + all->f->so
		+ all->f->we + all->f->ea + all->f->s == 8)
		return (1);
	return (0);
}

int	map_scan(t_all *all)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (all->map[++i])
	{
		if (config_reader(all, all->map[i]))
		{
			j = -1;
			if (i < 8)
				i++;
			while (all->map[i][++j])
			{
				check_map(all, &all->map[i][j]);
				if (ft_strchr("NWSE", all->map[i][j]))
					player++;
				if (all->map[i][j] == '2')
					all->spr->count++;
			}
		}
	}
	check_params(all, player);
	return (1);
}

int	parcer(int argc, char **argv, t_all *all)
{
	int	i;

	if (argc == 1 || argc > 3)
		exit_point(all, 1, 1);
	i = ft_strnstr(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4);
	if (!i)
		exit_point(all, 5, 1);
	if (argv[0][6] != 'D')
		exit_point(all, 9, 1);
	map_reading(argv, all);
	map_scan(all);
	return (0);
}
