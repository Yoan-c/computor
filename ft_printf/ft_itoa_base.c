/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:33:45 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 14:33:47 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_size(intmax_t nb)
{
	int		n;

	n = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / 10;
		n++;
	}
	return (n);
}

static int	ft_size2(unsigned long long nb)
{
	int		n;

	n = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		n++;
	}
	return (n);
}

char		*ft_itoa_base(intmax_t nb, int base)
{
	static char	*tab = "0123456789ABCDEF";
	char		*str;
	int			i;
	int			size;

	i = 0;
	if (base > 16 || base < 2 || nb == 0)
		return (ft_strdup("0"));
	size = ft_size(nb);
	str = ft_strnew(size);
	size = 0;
	while (nb > 0)
	{
		str = ft_strjoin_char(str, tab[nb % base]);
		nb = nb / base;
	}
	str = ft_strrev(str);
	return (str);
}

char		*ft_uitoa_base(uintmax_t nb, int base)
{
	static char	tab[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F'};
	char		*str;
	int			i;
	int			size;

	i = 0;
	if (base > 16 || base < 2 || nb == 0)
		return (ft_strdup("0"));
	size = ft_size2(nb);
	str = ft_strnew(size);
	size = 0;
	while (nb > 0)
	{
		str = ft_strjoin_char(str, tab[nb % base]);
		nb = nb / base;
	}
	str = ft_strrev(str);
	return (str);
}
