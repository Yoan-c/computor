/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:29:35 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:11:07 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_size_int(intmax_t nb, t_info *e)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		e->neg = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_intochar(intmax_t nb, t_info *e)
{
	int		i;
	char	*n;
	int		j;

	j = 0;
	if (nb < 0)
		nb *= -1;
	i = ft_size_int(nb, e);
	n = ft_strnew(i);
	n[0] = '0';
	while (nb > 0)
	{
		n[j++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	n = ft_strrev(n);
	return (n);
}

char	*ft_check_d_nb_n(t_info *e, char *nb_n, intmax_t nb, int *size)
{
	if (nb == LLONG_MIN)
	{
		nb_n = ft_strdup("9223372036854775808");
		e->neg = 1;
		*size = ft_strlen(nb_n);
	}
	else
		nb_n = ft_intochar(nb, e);
	return (nb_n);
}

int		ft_fill_search(char *f_str, int i, t_info *e)
{
	i = 0;
	i = ft_strlen(f_str) - 1;
	while (i >= 0)
	{
		if ((f_str[i] == '-' || f_str[i] == ' ')
				&& e->flag && ft_strchr(e->flag, '0') == NULL &&
				ft_strchr(e->flag, '-') == NULL)
			break ;
		i--;
	}
	i = (i <= 0) ? 0 : i;
	return (i);
}

int		ft_fill_sp_d(t_info *e, char *str, int i)
{
	if (e->precision == 0 && e->flag && ft_strchr(e->flag, '0'))
	{
		e->precision = e->width;
		if (ft_strchr(e->flag, ' ') == NULL)
		{
			e->width = 0;
			return (i);
		}
		e->width = 1;
	}
	if (e->width > 0)
		while (e->width-- > 0)
			str[i++] = ' ';
	return (i);
}
