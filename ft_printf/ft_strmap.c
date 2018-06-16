/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:03:06 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/09 12:07:41 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr;
	char	*str;

	str = (char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	if (ptr && f)
	{
		while (s[i] != '\0')
		{
			ptr[i] = f(str[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
