/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:12:03 by ycoutena          #+#    #+#             */
/*   Updated: 2015/12/07 08:35:53 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	size;
	char	tmp;

	i = 0;
	size = ft_strlen(str);
	while (i < (size / 2))
	{
		tmp = str[i];
		str[i] = str[(size - 1) - i];
		str[(size - 1) - i] = tmp;
		i++;
	}
	return (str);
}
