/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:13:11 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:25:45 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strccpy(const char *s, char c)
{
	char			*ns;
	size_t			size;
	unsigned int	i;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size] && s[size] != c)
		size++;
	ns = ft_strnew(size + 1);
	if (!ns)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
