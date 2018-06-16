/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:50:56 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 15:21:56 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_fill_sp_s(t_info *e, char *f_str, int i)
{
	if (e->width > 0)
	{
		if (e->flag && ft_strchr(e->flag, '0'))
			while (e->width-- > 0)
				f_str[i++] = '0';
		else
		{
			while (e->width-- > 0)
				f_str[i++] = ' ';
		}
	}
	return (i);
}

void	ft_format_s(t_info *e, char *str, int size)
{
	int		i;
	char	*f_str;

	i = 0;
	f_str = ft_strnew(size + e->precision + e->width);
	if (e->flag && ft_strchr(e->flag, '-') && str &&
			(!ft_strcmp(str, "\0")) == 0)
	{
		i = ft_fill_str(e, str, f_str, i);
		i = ft_fill_sp_s(e, f_str, i);
	}
	else
	{
		i = ft_fill_sp_s(e, f_str, i);
		i = ft_fill_str(e, str, f_str, i);
	}
	e->str_f = f_str;
	e->ret += ft_strlen(f_str);
}

void	ft_check_s(t_info *e, int size, char *str)
{
	if (e->precision >= e->width)
	{
		if (e->width < size)
			e->width = 0;
		else
			e->width -= size;
	}
	if (e->width > size && e->precision == 0)
		e->width -= size;
	if (str && (!ft_strcmp(str, "\0")) == 0 && e->precision < e->width)
	{
		if (e->precision > size)
			e->width -= size;
		else
			e->width = e->width - e->precision;
	}
	if (str && (!ft_strcmp(str, "\0")) == 0 && e->precision >= size)
		e->precision = size;
	ft_format_s(e, str, size);
	ft_putstr(e->str_f);
	ft_strdel(&e->str_f);
}

void	ft_type_s_next(t_info *e, char *str)
{
	int	size;

	size = ft_strlen(str);
	if (e->str && ft_strchr(e->str, '.') != NULL && e->precision == 0)
	{
		str = ft_strnew(size);
		while (size > 0)
			str[size--] = ' ';
	}
	ft_check_s(e, size, str);
}

void	ft_type_s(t_info *e, va_list *ap)
{
	char	*str;

	str = NULL;
	if ((e->modif && ft_strcmp(e->modif, "l") == 0) || e->type == 'S')
	{
		ft_type_lc_ls(e, ap, 1);
		return ;
	}
	str = va_arg(*ap, char*);
	if (!str)
	{
		if (e->flag && ft_strchr(e->flag, '0'))
		{
			e->ret += e->width;
			while (e->width-- > 0)
				ft_putchar('0');
			return ;
		}
		else
			ft_putstr("(null)");
		e->ret += 6;
		return ;
	}
	ft_type_s_next(e, str);
}
