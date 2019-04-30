/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:19:12 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/28 20:51:33 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;

	loc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			loc = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)(s));
	return (loc);
}
