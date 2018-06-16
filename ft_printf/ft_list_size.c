/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:34:38 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/14 17:16:01 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list2 *begin_list)
{
	int		i;
	t_list2	*list;

	list = begin_list;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
