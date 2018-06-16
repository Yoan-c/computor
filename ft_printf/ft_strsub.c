/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:20:51 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/04 10:50:50 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ptr;

	i = 0;
	if (s)
	{
		ptr = ft_strnew(len);
		if (ptr)
		{
			while (i < len)
			{
				ptr[i] = s[start];
				start++;
				i++;
			}
		}
		return (ptr);
	}
	return (NULL);
}
