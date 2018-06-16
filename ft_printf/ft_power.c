/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:40:14 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/07 08:58:49 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int pow)
{
	int i;
	int num;

	i = 1;
	num = nb;
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (-1);
	else
		while (i < pow)
		{
			num = num * nb;
			i++;
		}
	return (num);
}
