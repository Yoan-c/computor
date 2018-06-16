/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:04:17 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:07:16 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_conver_mask_lc2(t_info *e, char *tmp, int size)
{
	if (size <= 21)
	{
		e->mask = ft_conver_lc(e->tab[3], tmp, size);
		e->octet[0] = ft_btod(e->mask[0], ft_strlen(e->mask[0]));
		e->octet[1] = ft_btod(e->mask[1], ft_strlen(e->mask[1]));
		e->octet[2] = ft_btod(e->mask[2], ft_strlen(e->mask[2]));
		e->octet[3] = ft_btod(e->mask[3], ft_strlen(e->mask[3]));
		ft_strdel(&e->mask[0]);
		ft_strdel(&e->mask[1]);
		ft_strdel(&e->mask[2]);
		ft_strdel(&e->mask[3]);
		e->ret += 4;
		e->nb_o = 4;
	}
	else
	{
		e->ret = -1;
		e->nb_o = -1;
	}
}

void	ft_conver_mask_lc1(t_info *e, char *tmp, int size)
{
	if (size <= 16)
	{
		e->mask = ft_conver_lc(e->tab[2], tmp, size);
		e->octet[0] = ft_btod(e->mask[0], ft_strlen(e->mask[0]));
		e->octet[1] = ft_btod(e->mask[1], ft_strlen(e->mask[1]));
		e->octet[2] = ft_btod(e->mask[2], ft_strlen(e->mask[2]));
		ft_strdel(&e->mask[0]);
		ft_strdel(&e->mask[1]);
		ft_strdel(&e->mask[2]);
		e->ret += 3;
		e->nb_o = 3;
	}
	else
		ft_conver_mask_lc2(e, tmp, size);
}

void	ft_conver_mask_lc(t_info *e, char *tmp, int size)
{
	if (size <= 7)
	{
		e->mask = ft_conver_lc(e->tab[0], tmp, size);
		e->octet[0] = ft_btod(e->mask[0], ft_strlen(e->mask[0]));
		ft_strdel(&e->mask[0]);
		e->ret += 1;
		e->nb_o = 1;
	}
	else if (size <= 11)
	{
		e->mask = ft_conver_lc(e->tab[1], tmp, size);
		e->octet[0] = ft_btod(e->mask[0], ft_strlen(e->mask[0]));
		e->octet[1] = ft_btod(e->mask[1], ft_strlen(e->mask[1]));
		ft_strdel(&e->mask[0]);
		ft_strdel(&e->mask[1]);
		e->ret += 2;
		e->nb_o = 2;
	}
	else
		ft_conver_mask_lc1(e, tmp, size);
}

void	ft_lc_ls(t_info *e, wchar_t val, int j)
{
	char	*tmp;
	int		size;

	e->tab = malloc(sizeof(char*) * 4);
	e->tab[0] = ft_strdup("0xxxxxxx");
	e->tab[1] = ft_strdup("110xxxxx 10xxxxxx");
	e->tab[2] = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	e->tab[3] = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	tmp = ft_uitoa_base(val, 2);
	size = ft_strlen(tmp);
	ft_conver_mask_lc(e, tmp, size);
	ft_format_lc(e);
	ft_strdel(&tmp);
	j = 0;
}

int		ft_nbr_wchar_t(wchar_t val)
{
	char	*tmp;
	int		size;
	int		res;

	res = 0;
	tmp = ft_uitoa_base(val, 2);
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
	return (res);
}
