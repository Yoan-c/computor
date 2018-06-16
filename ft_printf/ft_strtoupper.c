/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:02:39 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/01 12:27:30 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	int		i;
	char	*ptr;

	ptr = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = ft_toupper(str[i]);
		i++;
	}
	return (ptr);
}
