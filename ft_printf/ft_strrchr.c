/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:12:18 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/15 18:12:21 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (tmp[i])
		i++;
	if (c == '\0')
		return (tmp + i);
	i--;
	while (tmp[i])
	{
		if ((char)tmp[i] == (char)c)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
