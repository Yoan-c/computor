/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:26:17 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/10 12:02:27 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	tmp = *alst;
	if (alst && *alst && del)
	{
		while (tmp)
		{
			list = tmp;
			tmp = tmp->next;
			del(list->content, list->content_size);
			free(list);
			*alst = tmp;
		}
		free(tmp);
		alst = NULL;
	}
}
