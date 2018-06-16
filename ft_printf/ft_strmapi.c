/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:10:09 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/09 12:08:06 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;
	char	*str;

	i = 0;
	str = (char *)s;
	if (s == NULL)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	if (ptr && f)
	{
		while (s[i] != '\0')
		{
			ptr[i] = f(i, str[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
