/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 22:25:02 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/04 23:32:44 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*ns;
	size_t				size;
	unsigned int		j;

	size = 0;
	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	while (s[size] && !ft_strspace(s + size))
		size++;
	ns = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!ns)
		return (NULL);
	j = 0;
	while (j < size)
	{
		ns[j] = s[j];
		j++;
	}
	ns[j] = '\0';
	return (ns);
}
