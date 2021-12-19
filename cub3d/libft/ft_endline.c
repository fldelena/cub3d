/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:24:25 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/14 16:54:43 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endline(char *fullstr)
{
	int	i;

	i = 0;
	if (!fullstr)
		return (0);
	while (fullstr[i])
	{
		if (fullstr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
