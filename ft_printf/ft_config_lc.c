/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:57:13 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:19:44 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_btod(char *str, int size)
{
	int	i;
	int	j;
	int	res;
	int	k;

	size--;
	res = 0;
	i = 0;
	j = 0;
	k = 1;
	while (size >= 0)
	{
		k = 1;
		j = i;
		if (str[size] == '1')
		{
			while (j-- > 0)
				k = k * 2;
			res += k;
		}
		i++;
		size--;
	}
	return (res);
}

char	**ft_conver_lc(char *tab, char *str, int size)
{
	int		j;
	char	**t;

	j = ft_strlen(tab);
	j--;
	size--;
	while (j >= 0)
	{
		if (size >= 0)
		{
			if (tab[j] == 'x')
				tab[j] = str[size--];
		}
		j--;
	}
	j = (j <= 0) ? 0 : j;
	while (tab[j])
	{
		if (tab[j] == 'x')
			tab[j] = '0';
		j++;
	}
	t = ft_strsplit(tab, ' ');
	return (t);
}

void	ft_putlc(t_info *e, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		write(1, &e->octet	[i++], 1);
	}
}

void	ft_format_lc(t_info *e)
{
	ft_putlc(e, e->nb_o);
}
