/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u_U.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:31:17 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/30 08:36:14 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_size_uint(uintmax_t nb)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_uintochar(uintmax_t nb)
{
	int		i;
	char	*n;
	int		j;

	j = 0;
	i = ft_size_uint(nb);
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

void	ft_format_u(t_info *e, char *nb, int size)
{
	char	*f_str;
	int		i;

	i = 0;
	f_str = ft_strnew(size + e->precision + e->width);
	if (e->flag && ft_strchr(e->flag, '-'))
	{
		i = ft_fill_z(e, f_str, i);
		f_str = ft_strjoin(f_str, nb);
		i = ft_strlen(f_str);
		i = ft_fill_sp(e, f_str, i);
		f_str[i] = '\0';
	}
	else
	{
		i = ft_fill_sp(e, f_str, i);
		i = ft_fill_z(e, f_str, i);
		f_str = ft_strjoin(f_str, nb);
	}
	e->str_f = f_str;
	e->ret += ft_strlen(f_str);
}

void	ft_type_u_next(t_info *e, int size, char *nb_n)
{
	int	total;

	total = size;
	if (e->precision > e->width || e->width <= size)
		e->width = 0;
	if (e->precision > size)
		e->precision = e->precision - size;
	else
		e->precision = 0;
	if (e->width > size)
		e->width = e->width - size;
	if (e->width >= e->precision)
		e->width -= e->precision;
	ft_format_u(e, nb_n, size);
	ft_putstr(e->str_f);
	ft_strdel(&e->str_f);
}

void	ft_type_u(t_info *e, va_list *ap)
{
	intmax_t		nb;
	int				size;
	char			*nb_n;
	uintmax_t		num;

	nb = 0;
	num = 0;
	ft_modif_convert(e, ap, &nb, &num);
	size = ft_size_uint(num);
	nb_n = ft_uintochar(num);
	if (num == 0)
	{
		size++;
		if (ft_strchr(e->str, '.') != NULL && e->precision == 0)
		{
			nb_n[0] = ' ';
			if (e->precision == 0 && e->width == 0)
			{
				ft_putstr("");
				return ;
			}
		}
	}
	ft_type_u_next(e, size, nb_n);
}
