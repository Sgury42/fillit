/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:54:58 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/07 00:58:38 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ns;
	int		i;

	if (!s)
		return (NULL);
	ns = ft_strnew(ft_strlen(s));
	if (!ns)
		return (NULL);
	i = -1;
	while (*s)
	{
		ns[++i] = (*f)(*s);
		s++;
	}
	ns[++i] = '\0';
	return (ns);
}
