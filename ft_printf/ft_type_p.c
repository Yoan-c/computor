/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:42:04 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 15:25:54 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_check_ox(char *str)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	if (size > 0)
	{
		i = 0;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i++] == '0' && str[i] == 'x')
			return ;
		if (str[i] == '0')
		{
			str[i++] = 'x';
			while (str[i] && str[i] != 'x')
				i++;
			str[i] = '0';
		}
	}
}

void	ft_format_p_next(t_info *e, char *f_str)
{
	if (e->flag && ft_strchr(e->flag, '-') && e->width > 0)
		while (e->width-- > 0)
		{
			ft_putchar(' ');
			e->ret++;
		}
	e->ret += ft_strlen(f_str);
	ft_strdel(&f_str);
}

void	ft_format_p(t_info *e, char *nb, int size)
{
	char	*f_str;
	int		i;

	i = 0;
	f_str = ft_strnew(size + e->precision + e->width);
	if (e->flag && ft_strchr(e->flag, '-'))
	{
		if (ft_strchr(e->flag, ' ') && e->width--)
			f_str[i++] = ' ';
		i = ft_fill_z_p(e, f_str, i);
		f_str = ft_cleanjoin(f_str, nb);
		i = ft_strlen(f_str);
	}
	else
	{
		i = ft_fill_sp(e, f_str, i);
		i = ft_fill_z_p(e, f_str, i);
		if (ft_strcmp(nb, "0") == 0)
			f_str = ft_cleanjoin(ft_strdup("0x0"), f_str);
		else
			f_str = ft_cleanjoin(f_str, nb);
	}
	ft_check_ox(f_str);
	ft_putstr(f_str);
	ft_format_p_next(e, f_str);
}

void	ft_type_p_next(t_info *e, char *nb_n, int size)
{
	int	i;

	i = 0;
	if (e->width < 0)
		e->width = 0;
	if ((ft_strcmp(nb_n, "0") == 0 && e->precision > 0))
		e->precision -= ft_strlen(nb_n) + 1;
	if (e->precision < size)
		e->precision = 0;
	if (e->precision > size && ft_strcmp(nb_n, "0") != 0)
		e->precision -= size + 1;
	if (e->precision > 0)
		e->width -= e->precision + 1;
	i = ft_strlen(nb_n);
	while (i > 0)
	{
		if (ft_isalpha(nb_n[i]))
			nb_n[i] = ft_tolower(nb_n[i]);
		i--;
	}
	e->s_alloc = (size + e->precision + e->width);
	ft_format_p(e, nb_n, size);
}

void	ft_type_p(t_info *e, va_list *ap)
{
	void	*ptr;
	int		size;
	char	*nb_n;
	char	*tmp;

	ptr = va_arg(*ap, void*);
	nb_n = ft_uitoa_base((uintmax_t)ptr, 16);
	size = ft_strlen(nb_n);
	if (ft_strcmp(nb_n, "0") == 0)
		if (ft_strchr(e->str, '.') != NULL && e->precision == 0)
			nb_n[0] = 0;
	if (ft_strcmp(nb_n, "0") == 0 && e->flag && ft_strchr(e->flag, '0'))
		e->width--;
	if (!(ft_strcmp(nb_n, "0") == 0 && e->precision > 0))
	{
		tmp = nb_n;
		nb_n = ft_strjoin("0x", nb_n);
		ft_strdel(&tmp);
	}
	e->width = e->width - ft_strlen(nb_n);
	e->width = (e->width >= 0) ? e->width : 0;
	ft_type_p_next(e, nb_n, size);
	ft_strdel(&nb_n);
}
