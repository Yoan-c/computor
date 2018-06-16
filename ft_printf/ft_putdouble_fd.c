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

double	ft_pow_precision(double nb, int precision)
{
	int	i;

	i = 0;
	while (i < precision)
	{
		nb *= 10.0;
		i++;
	}
	return (nb);
}

int		ft_length(int k)
{
	int i;
	
	i = 0;
	while (k > 0)
	{
		i++;
		k = k / 10;
	}
	return (i);
}

void	ft_printdbl(int k, int precision, char *str, int fd)
{
	int i;

	i = ft_length(k);
	while (k > 0)
	{
		str[i--] = '0' + (k % 10) ;
		if (precision-- == 1)
			str[i--] = '.';
		k = k / 10;
	}
	if (str[0] == '.')
		ft_putchar_fd('0', fd);
	ft_putstr(str);
	free(str);
}

int		ft_test_nb(double nb, int fd)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return (-1);
	}
	return (0);
}

void	ft_putdouble_fd(double nb, int precision, int fd)
{
	int		i;
	double	tmp;
	int		k;
	char	*str;

	if (ft_test_nb(nb, fd) == -1)
		return;
	if (precision > 0)
		nb = ft_pow_precision(nb, precision);
	else
	{
		ft_putnbr_fd(nb, fd);
		return ;
	}
	if (nb < 0.0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	tmp = nb;
	k = (int)(nb += 0.05);
	i = ft_length(k) + 1;
	str = ft_strnew(i);
	k = (int)(tmp += 0.05);
	ft_printdbl(k, precision, str, fd);
}
