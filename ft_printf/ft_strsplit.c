/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycoutena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:19:59 by ycoutena          #+#    #+#             */
/*   Updated: 2016/02/12 16:38:10 by ycoutena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nb_words(const char *s, char c)
{
	int		i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nb_words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (nb_words);
}

static int			ft_nb(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void			ft_words(const char *s, char c, char **tab)
{
	int j;
	int k;

	k = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			k = 0;
			tab[j] = ft_strnew(ft_nb(s, c));
			while (*s != c && *s != '\0')
			{
				tab[j][k++] = *s++;
			}
			j++;
		}
		if (*s != '\0')
			s++;
	}
	tab[j] = NULL;
}

char				**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	words;

	if (s && c)
	{
		words = ft_nb_words(s, c);
		tab = (char **)malloc(sizeof(char *) * (words + 1));
		if (!tab)
			return (NULL);
		ft_words(s, c, tab);
		return (tab);
	}
	return (NULL);
}
