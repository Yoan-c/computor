/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:28:05 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/15 18:28:07 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_sign(const char *str, int j)
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

static	int		ft_nbr(const char *str, int i, int j)
{
	int		nbr;

	nbr = 0;
	while (i > 0)
	{
		if (str[j] < '0' || str[j] > '9')
			break ;
		nbr = (nbr * 10) + (str[j] - '0');
		i--;
		j++;
	}
	return (nbr);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	size_t	j;
	int		nbr;
	int		neg;

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
