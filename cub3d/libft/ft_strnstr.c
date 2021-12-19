/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:22:56 by fldelena          #+#    #+#             */
/*   Updated: 2021/04/30 22:27:40 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *str1, const char *str2, size_t size)
{
	size_t	count;
	size_t	i;
	size_t	k;

	count = -1;
	if (!*str2)
		return (0);
	while (++count < size && *(str1 + count))
	{
		i = 0;
		if (*(str1 + count + i) == *(str2 + i))
		{
			k = 0;
			while (count + i < size + 1 && *(str1 + count + i) && *(str2 + i))
			{
				if (*(str1 + count + i) != *(str2 + i))
					break ;
				i++;
				k++;
			}
			if (k == ft_strlen(str2))
				return (1);
		}
	}
	return (0);
}
