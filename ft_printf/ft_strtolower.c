/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:11:31 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/01 12:26:46 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	int		i;
	char	*ptr;

	ptr = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = ft_tolower(str[i]);
		i++;
	}
	return (ptr);
}
