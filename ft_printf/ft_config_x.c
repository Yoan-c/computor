/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:06:07 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:12:20 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_check_x(t_info *e, int size, char *nb_n, uintmax_t num)
{
	if (num == 0)
	{
		size++;
		if (ft_strchr(e->str, '.') != NULL && e->precision == 0)
		{
			nb_n[0] = ' ';
			if (e->precision == 0 && e->width == 0)
			{
				ft_putstr("");
				return (1);
			}
		}
	}
	if (ft_strcmp(nb_n, "0") == 0)
	{
		ft_putchar('0');
		e->ret += 1;
		return (1);
	}
	return (0);
}

void	ft_check_size_x(t_info *e, int size)
{
	if (e->precision > e->width)
		e->width = 0;
	if (e->width < size)
		e->width = 0;
	if (e->precision < size)
		e->precision = 0;
	if (e->precision >= size)
		e->precision = e->precision - size;
	if (e->width >= size)
		e->width = e->width - size;
	if (e->width >= e->precision)
		e->width = e->width - e->precision;
	if (e->flag && (ft_strchr(e->flag, '#') &&
		(e->flag && (ft_strchr(e->flag, '0') || ft_strchr(e->flag, '-')))))
	{
		if (e->width < 2)
			e->width = 0;
		else
			e->width -= 2;
	}
}

int		ft_search_x(t_info *e, int i, char *f_str)
{
	i = ft_strlen(f_str) - 1;
	while (i >= 0)
	{
		if (f_str[i] == ' ' && e->flag && ft_strchr(e->flag, '-') == NULL)
			break ;
		i--;
	}
	i = (i < 0) ? 0 : i;
	return (i);
}
