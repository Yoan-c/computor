/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 08:54:37 by ycoutena          #+#    #+#             */
/*   Updated: 2016/03/29 14:35:57 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cleanjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else
	{
		tmp = s1;
		s1 = ft_strjoin(s1, s2);
		ft_strdel(&tmp);
		return (s1);
	}
}
