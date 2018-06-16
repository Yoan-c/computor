/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:02:57 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:10:51 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_putwchar_tnbr(wchar_t *str)
{
	int		size;
	int		i;
	char	*tmp;
	int		res;

	res = 0;
	i = 0;
	size = 0;
	while (str[i] && str)
	{
		tmp = ft_uitoa_base(str[i], 2);
		size = ft_strlen(tmp);
		ft_strdel(&tmp);
		if (size <= 7)
			res += 1;
		else if (size <= 11)
			res += 2;
		else if (size <= 16)
			res += 3;
		else if (size <= 21)
			res += 4;
		i++;
	}
	return (res);
}

void	ft_format_ls_next2(t_info *e, char c, wchar_t *val_s, int i)
{
	int res;

	res = 0;
	while (e->width-- > 0)
		ft_putchar(c);
	if (e->str && !ft_strchr(e->str, '.'))
		while (val_s && val_s[i])
		{
			ft_lc_ls(e, val_s[i], 1);
			i++;
		}
	else
	{
		res = ft_nbr_wchar_t(val_s[i]);
		while (val_s && val_s[i] && res <= e->precision)
		{
			ft_lc_ls(e, val_s[i], 1);
			res += ft_nbr_wchar_t(val_s[i + 1]);
			i++;
		}
	}
}

void	ft_format_ls_next(t_info *e, char c, wchar_t *val_s, int i)
{
	if (e->precision < e->width)
		e->ret += e->width;
	i = 0;
	e->width = (e->width <= 0) ? 0 : e->width;
	if (e->flag && ft_strchr(e->flag, '-'))
	{
		while (val_s && val_s[i])
		{
			ft_lc_ls(e, val_s[i], 1);
			i++;
		}
		while (e->width-- > 0)
			ft_putchar(c);
	}
	else
		ft_format_ls_next2(e, c, val_s, i);
}

void	ft_format_ls(t_info *e, wchar_t *val_s)
{
	int		size;
	int		i;
	char	c;
	int		res;

	res = 0;
	i = 0;
	c = (e->flag && ft_strchr(e->flag, '0') != NULL) ? '0' : ' ';
	size = ft_putwchar_tnbr(val_s);
	if (e->width > 0 && e->precision > 0)
	{
		res += ft_nbr_wchar_t(val_s[i]);
		while (val_s && val_s[i] &&
				(res + ft_nbr_wchar_t(val_s[i + 1]) < e->precision))
			res += ft_nbr_wchar_t(val_s[++i]);
		e->width -= res;
	}
	else if (e->width > 0 && e->width > size)
		e->width -= size;
	ft_format_ls_next(e, c, val_s, i);
}

void	ft_type_lc_ls(t_info *e, va_list *ap, int j)
{
	wchar_t		val_c;
	wchar_t		*val_s;

	if (j == 0)
	{
		val_c = va_arg(*ap, wchar_t);
		ft_lc_ls(e, val_c, 0);
	}
	else if (j == 1)
	{
		val_s = va_arg(*ap, wchar_t*);
		if (val_s)
			ft_format_ls(e, val_s);
		else
		{
			ft_putstr("(null)");
			e->ret += 6;
		}
	}
}
