/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:40:35 by ycoutena          #+#    #+#             */
/*   Updated: 2016/02/10 08:32:19 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_delspace(char *str, int len)
{
	char	*ptr;
	int		i;
	int		k;

	i = 0;
	k = 0;
	ptr = (char *)malloc(sizeof(char *) * len);
	len--;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t')
		len--;
	while (i <= len)
	{
		ptr[k] = str[i];
		i++;
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}

char		*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = ft_delspace((char *)s, (int)ft_strlen(s));
	if (!str)
		return (NULL);
	return (str);
}
