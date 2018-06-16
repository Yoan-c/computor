/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:35:48 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/14 17:15:37 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_list_last(t_list2 *begin_list)
{
	t_list2 *list;

	list = begin_list;
	while (list->next)
		list = list->next;
	return (list);
}
