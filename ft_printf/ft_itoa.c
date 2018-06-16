/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:21:03 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/13 13:53:53 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nb(char *str, int n, int size)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -(n);
		while (size > 0)
		{
			str[size] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
		return (str);
	}
	while (size >= 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

static int	ft_len(int nb, int size)
{
	if (nb < 0)
	{
		size++;
		nb = -(nb);
	}
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nb;
	int		size;

	size = 0;
	nb = n;
	size = ft_len(nb, size);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	if (n == 0)
		return (ft_strdup("0"));
	if (str)
	{
		size--;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		return (ft_nb(str, n, size));
	}
	return (NULL);
}
