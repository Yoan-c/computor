/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 08:12:17 by ycoutena          #+#    #+#             */
/*   Updated: 2017/10/02 14:36:37 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_check_nb(double nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}

int		ft_cast_int(double nb, int fd)
{
	int	i;

	i = (int)nb;
	if (nb < 0 && i == 0)
		ft_putchar_fd('-', fd);
	i = (int)nb;
	return (i);
}

void	ft_putdouble_fd(double nb, int precision, int fd)
{
	int		i;
	double	nb2;
	int		k;

	i = ft_cast_int(nb, fd);
	ft_putnbr_fd(i, fd);
	nb = nb - i;
	ft_putchar_fd('.', fd);
	nb = ft_check_nb(nb);
	if (precision < 1)
		precision = 1;
	while (precision >= 1)
	{
		nb = nb * 10;
		nb2 = nb;
		k = nb;
		nb2 = nb - k;
		nb2 = nb2 * 10;
		i = (int)nb;
		if (nb2 > 9)
			i++;
		ft_putnbr_fd(i, fd);
		nb = nb - i;
		precision--;
	}
}
