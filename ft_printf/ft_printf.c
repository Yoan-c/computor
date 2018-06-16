/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:27:30 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:39:48 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

char		*ft_strjoin_char(char *str, char c)
{
	char	*tmp;
	char	*tmp2;
	char	*ret;

	tmp = ft_strnew(2);
	tmp[0] = c;
	tmp[1] = '\0';
	tmp2 = str;
	ret = ft_strjoin(str, tmp);
	ft_strdel(&tmp2);
	ft_strdel(&tmp);
	return (ret);
}

void		ft_check_p2(char *str, t_info *e)
{
	char *tmp;

	if ((tmp = ft_strchr(str, '.')) != NULL)
	{
		e->precision = 0;
		tmp++;
		if (tmp && ft_isdigit(*tmp))
		{
			while (ft_isdigit(*tmp))
			{
				e->precision = e->precision * 10 + *tmp - '0';
				tmp++;
			}
		}
	}
}

void		ft_fill_all(t_info *e, char *str, int i, char *tmp)
{
	i = 0;
	e->flag = ft_check_flag(str);
	e->neg = 0;
	if (e->flag && ft_strchr(e->flag, '+') && ft_strchr(e->flag, ' '))
	{
		while (e->flag[i] != ' ')
			i++;
		e->flag[i] = '+';
	}
	tmp = ft_check_width(str, (ft_strlen(str) - 1));
	e->width = 0;
	if (tmp)
	{
		e->width = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	tmp = ft_check_precision(str, (ft_strlen(str) - 1));
	e->precision = 0;
	if (tmp)
	{
		e->precision = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	e->modif = ft_check_modif(str);
}

void		ft_format(char *str, va_list *ap, t_info *e)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	ft_fill_all(e, str, i, tmp);
	i = 0;
	while (i < 14)
	{
		if (e->fct[i].type == e->type)
		{
			e->fct[i].fct(e, ap);
			if (e->flag)
				ft_strdel(&e->flag);
			if (e->modif)
				ft_strdel(&e->modif);
			return ;
		}
		i++;
	}
	ft_type_c(e, ap);
	if (e->flag)
		ft_strdel(&e->flag);
	if (e->modif)
		ft_strdel(&e->modif);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	t_info	*e;
	int		res;

	e = ft_init();
	va_start(ap, str);
	ft_check2(str, e, &ap);
	va_end(ap);
	res = e->ret;
	free(e);
	return (res);
}
