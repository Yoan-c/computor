/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:34:22 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:39:54 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_sub(char *str, t_info *e, int i, va_list *ap)
{
	int j;

	j = i;
	while (str && str[i] && (ft_strchr(" hljz+-#0123456789.", str[i])))
		i++;
	e->str = ft_strsub(str, j, (i - j));
	if (str[i])
		e->type = str[i];
	else
		e->type = str[i - 1];
	i++;
	ft_format(e->str, ap, e);
	if (e->str)
		ft_strdel(&(e->str));
	e->str = NULL;
	ft_reinit(e);
	return (i);
}

static int	ft_affine(char *str, t_info *e, int i, va_list *ap)
{
	i++;
	if (str[i])
	{
		if (str[i] == '%')
		{
			ft_putchar(str[i]);
			e->ret++;
			return (++i);
		}
		else
		{
			i = ft_sub(str, e, i, ap);
		}
	}
	return (i);
}

void		ft_check2(char *str, t_info *e, va_list *ap)
{
	int	i;

	i = 0;
	e->ret = 0;
	while (str && str[i	])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			e->ret++;
			i++;
		}
		else
		{
			i = ft_affine(str, e, i, ap);
		}
	}
}
