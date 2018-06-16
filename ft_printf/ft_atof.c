/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:28:05 by ycoutena          #+#    #+#             */
/*   Updated: 2017/10/02 14:42:00 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_sign(const char *str, int j)
{
	int		sign;

	sign = 1;
	if (str[j] == '-')
	{
		j++;
		sign = -1;
	}
	return (sign);
}

static	float		ft_nbr(const char *str, int i, int j)
{
	float		nbr;
	float		flat;
	int			fl;

	fl = 0;
	flat = 1;
	nbr = 0;
	while (i > 0)
	{
		if ((str[j] < '0' || str[j] > '9') && str[j] != '.')
			break ;
		if (str[j] == '.')
			fl = 1;
		else
		{
			if (fl)
				flat /= 10.0f;
			nbr = (nbr * 10.0f) + (str[j] - '0');
		}
		i--;
		j++;
	}
	return (nbr * flat);
}

double				ft_atof(const char *str)
{
	size_t		i;
	size_t		j;
	float		nbr;
	int			neg;

	i = ft_strlen(str);
	j = 0;
	nbr = 0;
	neg = 1;
	while (ft_isspace(str[j]) == 1)
		j++;
	i = i - j;
	if (str[j] == '-' || str[j] == '+')
	{
		neg = ft_sign(str, j);
		j++;
		i--;
	}
	nbr = ft_nbr(str, i, j);
	return (nbr * neg);
}
