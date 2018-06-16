/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:27:39 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/10 12:03:15 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	if (f)
		list = f(lst);
	if (!list)
		return (NULL);
	tmp = list;
	if (f)
	{
		while (lst->next)
		{
			lst = lst->next;
			list->next = f(lst);
			if (!list->next)
				return (NULL);
			list = list->next;
		}
	}
	return (tmp);
}
