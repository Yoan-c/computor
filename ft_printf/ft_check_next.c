/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:39:12 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 14:40:05 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_check_modif(char *str)
{
	int		i;
	char	*p;
	int		j;

	i = 0;
	j = 0;
	p = ft_strnew(ft_strlen(str));
	while (str && str[i])
	{
		if (str[i] == 'h')
			p[j++] = 'h';
		else if (str[i] == 'l')
			p[j++] = 'l';
		else if (str[i] == 'j')
			p[j++] = 'j';
		else if (str[i] == 'z')
			p[j++] = 'z';
		i++;
	}
	(j == 0) ? free(p) : 0;
	p = (j == 0) ? NULL : p;
	return (p);
}
