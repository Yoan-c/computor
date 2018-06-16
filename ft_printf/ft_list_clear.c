/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:33:24 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/14 17:14:47 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list2 **begin_list)
{
	t_list2 *tmp;
	t_list2 *supp;

	tmp = *begin_list;
	while (tmp != NULL)
	{
		supp = tmp;
		tmp = tmp->next;
		free(supp);
		*begin_list = tmp;
	}
}
