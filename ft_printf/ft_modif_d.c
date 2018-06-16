/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:42:21 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/30 08:37:09 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_check_neg(char *str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	if ((tmp = ft_strchr(str, '-')) != NULL)
	{
		while (str && str[i] != '-')
			i++;
		if (str[i - 1] == '0')
		{
			*tmp = '0';
			while (i >= 0 && str[i] == '0')
				i--;
			i++;
			i = (i <= 0) ? 0 : i;
			str[i] = '-';
		}
	}
}

void	ft_fill_put_str(t_info *e, char **f_str, char *nb)
{
	ft_check_neg(*f_str);
	ft_putstr(*f_str);
	if (e->flag && ft_strchr(e->flag, '-') && e->width > 0)
		while (e->width-- >= 0)
		{
			ft_putchar(' ');
			e->ret++;
		}
	e->ret += ft_strlen(*f_str);
	ft_strdel(f_str);
	ft_strdel(&nb);
}

void	ft_modif_str_d2(t_info *e, char **f_str, intmax_t n)
{
	if (e->flag && ft_strchr(e->flag, '+'))
	{
		if (n < 0 && ft_strchr(*f_str, '-') == NULL)
			*f_str = ft_cleanjoin(ft_strdup("-"), *f_str);
		else
			*f_str = ft_cleanjoin(ft_strdup("+"), *f_str);
	}
	else
	{
		if (n < 0 && ft_strchr(*f_str, '-') == NULL)
			*f_str = ft_cleanjoin(ft_strdup("-"), *f_str);
	}
}

void	ft_modif_str_d(t_info *e, char **f_str, intmax_t n)
{
	if (e->flag && ft_strchr(e->flag, '+'))
	{
		if (n < 0 && ft_strchr(*f_str, '-') == NULL)
			*f_str = ft_cleanjoin(ft_strdup("-"), *f_str);
		else
			*f_str = ft_cleanjoin(ft_strdup("+"), *f_str);
	}
	else
	{
		if (n < 0 && ft_strchr(*f_str, '-') == NULL)
			*f_str = ft_cleanjoin(ft_strdup("-"), *f_str);
	}
}

void	ft_format_d(t_info *e, char *nb, intmax_t n)
{
	char	*f_str;
	int		i;

	i = 0;
	f_str = ft_memalloc(e->s_alloc);
	if (e->flag && ft_strchr(e->flag, '-'))
		i = ft_format_d_next_neg(e, &f_str, nb, n);
	else
		ft_format_d_next(e, &f_str, nb, n);
	i = ft_fill_search(f_str, i, e);
	if (i > 1)
		f_str[i] = (n >= 0 && e->flag && ft_strchr(e->flag, '+'))
			? '+' : f_str[i];
	else if (i == 1 && f_str[i])
	{
		f_str[i] = (n >= 0 && e->flag && ft_strchr(e->flag, '+'))
			? '+' : f_str[i];
		if (n < 0 && ft_strchr(f_str, '-') == NULL)
			f_str[i] = '-';
	}
	else
		ft_modif_str_d(e, &f_str, n);
	ft_fill_put_str(e, &f_str, nb);
}
