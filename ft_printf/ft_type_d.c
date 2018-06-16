/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:16:32 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/30 08:36:32 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_format_d_next(t_info *e, char **f_str, char *nb, intmax_t n)
{
	int i;

	i = 0;
	if (!e->flag && e->neg == 1 && ((e->width == 0 && e->precision > 0) ||
				(e->width > 0 && e->precision == 0)
				|| e->precision > 0 || e->width > 0))
	{
		nb = ft_strjoin("-", nb);
		e->width--;
	}
	if ((e->flag && ft_strchr(e->flag, '+') && n > 0))
		e->width--;
	i = ft_fill_sp_d(e, *f_str, i);
	if (i == 0 && e->flag && ft_strchr(e->flag, ' ') && n > 0)
		*f_str[i++] = ' ';
	i = ft_fill_z(e, *f_str, i);
	*f_str = ft_cleanjoin(*f_str, nb);
}

int		ft_format_d_next_neg(t_info *e, char **f_str, char *nb, intmax_t n)
{
	int i;

	i = 0;
	e->width--;
	if (ft_strchr(e->flag, '+'))
		e->width--;
	if (ft_strchr(e->flag, ' '))
		*f_str[i++] = ' ';
	i = ft_fill_z(e, *f_str, i);
	if (n < 0)
		nb = ft_strjoin("-", nb);
	*f_str = ft_cleanjoin(*f_str, nb);
	i = ft_strlen(*f_str);
	return (i);
}

void	ft_type_d_next(t_info *e, int size, char *nb_n, intmax_t nb)
{
	if (e->precision <= size)
		e->precision = 0;
	if (e->precision > size)
	{
		e->precision -= size;
		e->width -= e->precision;
	}
	if ((e->flag && (ft_strchr(e->flag, '-') ||
					ft_strchr(e->flag, '0')) && nb < 0) ||
			(e->flag && (ft_strchr(e->flag, '0') && nb < 0)))
		e->width--;
	if (e->flag && ft_strchr(e->flag, '+') &&
			ft_strchr(e->flag, '-') && e->precision > 0)
		e->width--;
	if (e->flag && (ft_strchr(e->flag, '+') ||
				ft_strchr(e->flag, ' ')) && ft_strchr(e->flag, '0') && nb == 0)
		e->width--;
	e->width = (e->width <= 0) ? 0 : e->width;
	e->s_alloc = (size + e->precision + e->width);
	ft_format_d(e, nb_n, nb);
}

void	ft_type_d_n(t_info *e, int size, intmax_t nb, char *nb_n)
{
	if (e->width > size)
	{
		e->width -= size;
		if (e->flag && e->precision > e->width &&
				e->precision > size && ft_strchr(e->flag, '0') == NULL)
		{
			e->width = 0;
		}
		if (e->flag && ft_strchr(e->flag, '+') && e->precision > size)
			e->width++;
	}
	else if (e->width <= size)
		e->width = 0;
	ft_type_d_next(e, size, nb_n, nb);
}

void	ft_type_d(t_info *e, va_list *ap)
{
	intmax_t		nb;
	int				size;
	char			*nb_n;
	uintmax_t		num;

	nb_n = NULL;
	ft_modif_convert(e, ap, &nb, &num);
	size = ft_size_int(nb, e);
	nb_n = ft_check_d_nb_n(e, nb_n, nb, &size);
	if (nb == 0)
	{
		size++;
		if (ft_strchr(e->str, '.') != NULL &&
				e->precision == 0 && !e->flag && e->nb == 0 && !e->modif)
		{
			nb_n[0] = ' ';
			if (e->precision == 0 && e->width == 0)
			{
				ft_putstr("");
				return ;
			}
		}
	}
	ft_type_d_n(e, size, nb, nb_n);
}
