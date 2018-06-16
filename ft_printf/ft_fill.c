/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:46:11 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 15:28:31 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_fill_sp(t_info *e, char *str, int i)
{
	if (e->width > 0)
	{
		if (e->flag && e->precision == 0 && ft_strchr(e->flag, '0'))
		{
			e->precision = e->width;
			e->width = 0;
		}
		if (e->flag && ft_strchr(e->flag, '0') &&
				e->precision > 0)
		{
			if (ft_strchr(e->flag, ' '))
			{
				e->width--;
				str[i++] = ' ';
			}
			while (e->width-- > 0)
				str[i++] = ' ';
		}
		else
			while (e->width-- > 0)
				str[i++] = ' ';
	}
	return (i);
}

int	ft_fill_z(t_info *e, char *str, int i)
{
	if (e->precision > 0)
		while (e->precision-- > 0)
			str[i++] = '0';
	return (i);
}

int	ft_fill_str(t_info *e, char *str, char *f_str, int i)
{
	int	j;

	j = 0;
	if (e->precision > 0 && str)
		while (e->precision-- > 0)
			f_str[i++] = str[j++];
	else if (e->precision == 0 && str)
		while (str[j])
			f_str[i++] = str[j++];
	return (i);
}

int	ft_fill_z_p(t_info *e, char *str, int i)
{
	if (e->precision > 0)
		while (e->precision-- >= 0)
			str[i++] = '0';
	return (i);
}
