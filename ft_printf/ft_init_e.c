/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:20:37 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 16:23:55 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_init_fct(t_info *e)
{
	e->fct[0].fct = &ft_type_s;
	e->fct[1].fct = &ft_type_s;
	e->fct[2].fct = &ft_type_p;
	e->fct[3].fct = &ft_type_d;
	e->fct[4].fct = &ft_type_d;
	e->fct[5].fct = &ft_type_d;
	e->fct[6].fct = &ft_type_o;
	e->fct[7].fct = &ft_type_o;
	e->fct[8].fct = &ft_type_u;
	e->fct[9].fct = &ft_type_u;
	e->fct[10].fct = &ft_type_x;
	e->fct[11].fct = &ft_type_x;
	e->fct[12].fct = &ft_type_c;
	e->fct[13].fct = &ft_type_c;
}

void	ft_init_type(t_info *e)
{
	e->fct[0].type = 's';
	e->fct[1].type = 'S';
	e->fct[2].type = 'p';
	e->fct[3].type = 'd';
	e->fct[4].type = 'D';
	e->fct[5].type = 'i';
	e->fct[6].type = 'o';
	e->fct[7].type = 'O';
	e->fct[8].type = 'u';
	e->fct[9].type = 'U';
	e->fct[10].type = 'x';
	e->fct[11].type = 'X';
	e->fct[12].type = 'c';
	e->fct[13].type = 'C';
}

t_info	*ft_init(void)
{
	t_info *e;

	e = malloc(sizeof(t_info));
	if (!e)
		return (NULL);
	e->str = NULL;
	e->str_f = NULL;
	e->flag = NULL;
	e->modif = NULL;
	e->tab = NULL;
	e->mask = NULL;
	ft_init_type(e);
	ft_init_fct(e);
	return (e);
}

void	ft_reinit(t_info *e)
{
	e->flag = NULL;
	e->width = -1;
	e->precision = -1;
	e->modif = NULL;
	e->type = '\0';
	e->nb = 0;
	e->neg = 0;
	e->nb_o = 0;
	if (e->tab)
	{
		ft_strdel(&e->tab[0]);
		ft_strdel(&e->tab[1]);
		ft_strdel(&e->tab[2]);
		ft_strdel(&e->tab[3]);
	}
	free(e->tab);
	free(e->mask);
	e->tab = NULL;
	e->mask = NULL;
}
