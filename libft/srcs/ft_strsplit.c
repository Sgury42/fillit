/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:49:04 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/17 20:06:13 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*ft_strsplitdel(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbw;
	int		i;

	if (!s)
		return (NULL);
	nbw = ft_count_words(s, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (nbw + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < nbw && *s)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strnew(ft_strclen(s, c) + 1);
		if (!tab[i])
			return (ft_strsplitdel(tab));
		ft_strncpy(tab[i], s, ft_strclen(s, c));
		tab[i][ft_strclen(s, c)] = '\0';
		while (*s && *s != c)
			s++;
	}
	tab[i] = (char *)('\0');
	return (tab);
}
