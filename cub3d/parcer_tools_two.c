/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_tools_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:10:56 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 15:47:16 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	count_lines(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	return (i);
}

int	max_len(char **ar)
{
	size_t	max;
	int		i;

	i = -1;
	max = 0;
	while (ar[++i])
		if (ft_strlen(ar[i]) > max)
			max = ft_strlen(ar[i]);
	return (max);
}

int	flood_fill(int x, int y, char n, char **map)
{
	if (x < 0 || y < 0 || x >= max_len(map) || y >= count_lines(map)
		|| map[y][x] == ' ' || map[y][x] == 0)
	{
		print_error(5);
		exit(1);
		return (-1);
	}
	if (map[y][x] != n && map[y][x] != ' ' && map[y][x] != '1' &&
															map[y][x] != 0)
	{
		map[y][x] = n;
		flood_fill(x, y - 1, n, map);
		flood_fill(x, y + 1, n, map);
		flood_fill(x + 1, y, n, map);
		flood_fill(x - 1, y, n, map);
		flood_fill(x + 1, y + 1, n, map);
		flood_fill(x - 1, y - 1, n, map);
		flood_fill(x - 1, y + 1, n, map);
		flood_fill(x + 1, y - 1, n, map);
	}
	return (0);
}

char	**copy_map(char **map)
{
	char	**m;
	int		i;

	i = -1;
	m = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (!m)
		return (0);
	while (map[++i])
		m[i] = ft_strdup(map[i]);
	m[i] = 0;
	return (m);
}

int	ft_flood(char **map, int k, int j)
{
	char	**m;

	m = copy_map(map);
	if (flood_fill(k, j, '+', m) == -1)
	{
		free_arr(m);
		return (-1);
	}
	free_arr(m);
	return (0);
}
