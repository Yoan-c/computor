/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:12:38 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/15 18:17:24 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s2[i] != '\0')
		i++;
	while (j < i && s1[k])
	{
		if (s2[j] == s1[k])
			j++;
		else
		{
			k = k - j;
			j = 0;
		}
		k++;
	}
	if (i != j)
		return (NULL);
	return ((char*)(s1 + (k - i)));
}
