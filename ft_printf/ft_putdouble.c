/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 08:12:17 by ycoutena          #+#    #+#             */
/*   Updated: 2017/10/02 14:26:58 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_putdouble(double nb, int precision)
{
	if (precision > 0)
		ft_putdouble_fd(nb, precision, 1);
	else
		ft_putnbr_fd(nb, 1);
}
