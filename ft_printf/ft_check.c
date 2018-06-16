/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 12:53:31 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 14:40:49 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_check_zero(char *str)
{
	int i;

	i = 0;
	if (str && ft_strchr(str, '-') == NULL)
		while (str && str[i])
		{
			if (str && str[i] == '0' &&
					ft_isdigit(str[i - 1]) == 0 && str[i - 1] != '.')
				return (1);
			i++;
		}
	return (0);
}

void			*ft_check_flag(char *str)
{
	static char flag[4] = {'-', '+', ' ', '#'};
	int			i;
	int			j;
	char		*opt;

	opt = ft_strnew(ft_strlen(str));
	i = 0;
	j = 0;
	if (ft_check_zero(str) == 1)
		opt[j++] = '0';
	while (str && str[i])
	{
		if (ft_strchr(flag, str[i]))
		{
			if (ft_strchr(opt, str[i]) == NULL)
			{
				opt[j++] = str[i];
			}
		}
		i++;
	}
	(j == 0) ? ft_strdel(&opt) : 0;
	opt = (j == 0) ? NULL : opt;
	return (opt);
}

char			*ft_check_width(char *str, int i)
{
	int		j;
	char	*width;

	width = NULL;
	while (i >= 0 && str[i] && str)
	{
		if (i >= 0 && str[i] && ft_isdigit(str[i]))
		{
			j = i;
			while (i >= 0 && str && ft_isdigit(str[i]) == 1 && str[i] != '.')
				i--;
			i++;
			if ((i == 0 && str[i] != '.')
					|| (i >= 0 && str && str[i - 1] != '.'))
			{
				width = ft_strsub(str, i, (j - i) + 1);
				return (width);
			}
		}
		i--;
	}
	return (width);
}

char			*ft_check_precision(char *str, int i)
{
	char	*p;
	int		j;

	j = 0;
	p = NULL;
	while (i >= 0 && str[i] && str)
	{
		if (i >= 0 && str && str[i] == '.')
		{
			if (ft_isdigit(str[i + 1]))
			{
				i++;
				j = i;
				while (str && str[i] && ft_isdigit(str[i]) == 1)
					i++;
				i--;
				p = ft_strsub(str, j, (i - j) + 1);
				return (p);
			}
			p = ft_strdup("0");
		}
		if (str[i])
			i--;
	}
	return (p);
}

void			ft_check_p(char *str, t_info *e)
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
