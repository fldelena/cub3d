/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:26:59 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/01 15:07:22 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*oldlst;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		oldlst = *lst;
		*lst = oldlst->next;
		free(oldlst);
	}
	*lst = NULL;
}
