/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:06:26 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/30 08:36:04 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_put_x(t_info *e, char *f_str, int i)
{
	i = ft_strlen(f_str);
	if (e->type == 'x')
		while (i >= 0)
		{
			if (ft_isalpha(f_str[i]))
				f_str[i] = ft_tolower(f_str[i]);
			i--;
		}
	e->str_f = f_str;
	e->ret += ft_strlen(f_str);
}

void	ft_format_x_next(t_info *e, char **f_str, int i)
{
	if (e->flag && ft_strchr(e->flag, '#'))
	{
		i = ft_strlen(*f_str) - 1;
		while (i >= 0)
		{
			if (*f_str[i] == ' ' && e->flag && ft_strchr(e->flag, '-') == NULL)
				break ;
			i--;
		}
		i = (i < 0) ? 0 : i;
		if (i == 0 && e->flag && ft_strchr(e->flag, '0'))
			i += (*f_str[i] == '0' && e->precision == 0) ? 1 : 0;
		if (i > 1)
		{
			*f_str[i - 1] = '0';
			*f_str[i] = 'x';
		}
		else if (i == 1 && f_str[i])
		{
			*f_str[0] = '0';
			*f_str[1] = 'x';
		}
		else
			*f_str = ft_strjoin("0X", *f_str);
	}
}

char	*ft_fill_x(t_info *e, int size, int i, char *nb)
{
	char *f_str;

	f_str = ft_strnew(size + e->precision + e->width);
	if (e->flag && ft_strchr(e->flag, '-'))
	{
		if (ft_strchr(e->flag, ' ') && e->width--)
			f_str[i++] = ' ';
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
	return (f_str);
}

void	ft_format_x(t_info *e, char *nb, int size)
{
	char	*f_str;
	int		i;

	i = 0;
	f_str = ft_fill_x(e, size, i, nb);
	if (e->flag && ft_strchr(e->flag, '#'))
	{
		i = ft_search_x(e, i, f_str);
		if (i == 0 && e->flag && ft_strchr(e->flag, '0'))
			i += (f_str[i] == '0' && e->precision == 0) ? 1 : 0;
		if (i > 1)
		{
			f_str[i - 1] = '0';
			f_str[i] = 'x';
		}
		else if (i == 1 && f_str[i])
		{
			f_str[0] = '0';
			f_str[1] = 'x';
		}
		else
			f_str = ft_strjoin("0X", f_str);
	}
	ft_put_x(e, f_str, i);
}

void	ft_type_x(t_info *e, va_list *ap)
{
	intmax_t			x;
	int					size;
	char				*nb_n;
	int					i;
	uintmax_t			num;

	size = 0;
	ft_modif_convert(e, ap, &x, &num);
	nb_n = ft_uitoa_base(num, 16);
	if (ft_check_x(e, size, nb_n, num))
		return ;
	i = ft_strlen(nb_n);
	size = i;
	ft_check_size_x(e, size);
	ft_format_x(e, nb_n, size);
	ft_putstr(e->str_f);
	ft_strdel(&nb_n);
	if (e->str_f)
		ft_strdel(&e->str_f);
}
