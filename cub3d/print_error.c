/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:47:09 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/28 13:47:45 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	print_error(int i)
{
	if (i == 1)
		printf("\033[31m""Error\nNumber of arguments mismatch!\n");
	if (i == 2)
		printf("\033[31m""Error\nInvalid map extension!\n");
	if (i == 3)
		printf("\033[31m""Error\nThe file does not exist!\n");
	if (i == 4)
		printf("\033[31m""Error\nWrong parametr!\n");
	if (i == 5)
		printf("\033[31m""Error\nWrong map!\n");
	if (i == 6)
		printf("\033[31m""Error\nThe problem with the player!\n");
	if (i == 7)
		printf("\033[31m""Error\nWrong argument --save!\n");
	if (i == 8)
		printf("\033[31m""Error\nWrong texture file!\n");
	if (i == 9)
		printf("\033[31m""Error\nWrong programm name!\n");
}
