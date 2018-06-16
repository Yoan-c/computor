/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:15:49 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:11:31 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_format_c_next(t_info *e, int l, int l2, char *c)
{
	e->str_f = c;
	e->ret += ft_strlen(c);
	if (l == 0 && l2 > 0)
	{
		e->str_f = "\0";
		ft_putnstr(c, e->ret);
	}
}

void		ft_format_c(t_info *e, int l, int size, int l2)
{
	char	*c;
	int		i;

	i = 0;
	c = ft_strnew(e->width + size);
	if (e->flag && ft_strchr(e->flag, '-'))
	{
		c[i++] = l;
		if (e->width > 0)
			while (e->width-- > 1)
				c[i++] = ' ';
	}
	else
	{
		if (e->width > 0)
			while (e->width-- > 1)
			{
				if (e->flag && ft_strchr(e->flag, '0'))
					c[i++] = '0';
				else
					c[i++] = ' ';
			}
		c[i] = l;
	}
	ft_format_c_next(e, l, l2, c);
}

static void	ft_type_c_next(t_info *e, int size, int l)
{
	if (e->precision >= e->width)
		e->width = 0;
	if (e->precision < e->width)
		e->width = e->width - e->precision;
	if (e->precision > size)
	{
		e->width = 0;
		e->precision = size;
	}
	if (e->precision < e->width && e->width <= size)
	{
		e->precision = size;
		e->width = 0;
	}
	ft_format_c(e, l, size, e->width);
	ft_putstr(e->str_f);
}

void		ft_type_c(t_info *e, va_list *ap)
{
	int	l;
	int	size;

	if ((e->modif && ft_strcmp(e->modif, "l") == 0) || e->type == 'C')
	{
		ft_type_lc_ls(e, ap, 0);
		return ;
	}
	if (e->type == 'c')
		l = (unsigned char)va_arg(*ap, int);
	else
		l = e->type;
	size = 1;
	if (l == 0)
	{
		l = '\0';
		e->ret += 1;
		if (e->width == 0)
		{
			write(1, "\0", 1);
			return ;
		}
	}
	ft_type_c_next(e, size, l);
}
