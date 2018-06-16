/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o_O.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:57:14 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/30 08:36:24 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_format_o(t_info *e, char *nb, int size)
{
	char	*f_str;
	int		i;

	i = 0;
	f_str = ft_strnew(size + e->precision + e->width);
	if (e->flag && ft_strchr(e->flag, '-'))
	{
		if (ft_strchr(e->flag, ' ') && e->width--)
			f_str[i++] = ' ';
		i = ft_fill_z(e, f_str, i);
		f_str = ft_strjoin(f_str, nb);
		i = ft_strlen(f_str);
		i = ft_fill_sp(e, f_str, i);
	}
	else
	{
		i = ft_fill_sp(e, f_str, i);
		i = ft_fill_z(e, f_str, i);
		f_str = ft_strjoin(f_str, nb);
	}
	ft_putstr(f_str);
	e->ret += ft_strlen(f_str);
	ft_strdel(&f_str);
}

void	ft_type_o_next(t_info *e, int size, int i, char *nb_n)
{
	size = i;
	if (e->precision > e->width || e->width < size)
		e->width = 0;
	if (e->precision <= size)
	{
		if (e->flag && ft_strchr(e->flag, '#'))
			e->precision = size + 1;
		else
			e->precision = 0;
	}
	if (e->precision > size)
		e->precision = e->precision - size;
	if (e->width >= size)
		e->width = e->width - size;
	if (e->width >= e->precision)
		e->width = e->width - e->precision;
	ft_format_o(e, nb_n, size);
}

void	ft_type_o(t_info *e, va_list *ap)
{
	intmax_t				x;
	int						size;
	char					*nb_n;
	int						i;
	uintmax_t				x2;

	size = 0;
	ft_modif_convert(e, ap, &x, &x2);
	nb_n = ft_uitoa_base(x2, 8);
	if (ft_strcmp(nb_n, "0") == 0)
		if (e->str && ft_strchr(e->str, '.') != NULL && e->precision == 0)
			nb_n[0] = 0;
	if ((ft_strcmp(nb_n, "0") == 0) && e->flag)
	{
		ft_putchar('0');
		e->ret += 1;
		ft_strdel(&nb_n);
		return ;
	}
	i = ft_strlen(nb_n);
	ft_type_o_next(e, size, i, nb_n);
}
