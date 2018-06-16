/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:13:12 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/30 08:36:58 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_convert(t_info *e, va_list *ap, intmax_t *x)
{
	if (e->type == 'D')
	{
		*x = (long)va_arg(*ap, long);
		return ;
	}
	if (e->modif && ft_strcmp(e->modif, "hh") == 0)
		*x = (signed char)va_arg(*ap, intmax_t);
	else if (e->modif && ft_strcmp(e->modif, "h") == 0)
		*x = (short int)va_arg(*ap, intmax_t);
	else if ((e->modif && ft_strcmp(e->modif, "l") == 0) || e->type == 'D')
		*x = (long int)va_arg(*ap, intmax_t);
	else if (e->modif && ft_strcmp(e->modif, "ll") == 0)
		*x = (long long int)va_arg(*ap, intmax_t);
	else if (e->modif && ft_strcmp(e->modif, "j") == 0)
		*x = (intmax_t)va_arg(*ap, intmax_t);
	else if (e->modif && ft_strcmp(e->modif, "z") == 0)
		*x = (size_t)va_arg(*ap, intmax_t);
	else
		*x = (int)va_arg(*ap, int);
	e->nb = *x;
}

static void	ft_uconvert(t_info *e, va_list *ap, uintmax_t *x2)
{
	if (e->type == 'U' || e->type == 'O')
	{
		*x2 = (unsigned long)va_arg(*ap, unsigned long);
		return ;
	}
	if (e->modif && ft_strcmp(e->modif, "hh") == 0)
		*x2 = (unsigned char)va_arg(*ap, uintmax_t);
	else if (e->modif && ft_strcmp(e->modif, "h") == 0)
		*x2 = (unsigned short int)va_arg(*ap, uintmax_t);
	else if ((e->modif && ft_strcmp(e->modif, "l") == 0))
		*x2 = (unsigned long int)va_arg(*ap, uintmax_t);
	else if (e->modif && ft_strcmp(e->modif, "ll") == 0)
		*x2 = (unsigned long long int)va_arg(*ap, uintmax_t);
	else if (e->modif && ft_strcmp(e->modif, "j") == 0)
		*x2 = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (e->modif && ft_strcmp(e->modif, "z") == 0)
		*x2 = (size_t)va_arg(*ap, uintmax_t);
	else
		*x2 = (unsigned int)va_arg(*ap, unsigned int);
}

void		ft_modif_convert(t_info *e, va_list *ap, intmax_t *x, uintmax_t *x2)
{
	if (e->type == 'd' || e->type == 'i' || e->type == 'D')
		ft_convert(e, ap, x);
	else if (e->type == 'o' || e->type == 'u' ||
			e->type == 'U' || e->type == 'x' ||
			e->type == 'X' || e->type == 'O')
		ft_uconvert(e, ap, x2);
}
