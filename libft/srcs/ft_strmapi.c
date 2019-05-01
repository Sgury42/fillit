/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:01:52 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:25:45 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		i;

	if (!s)
		return (NULL);
	ns = ft_strnew(ft_strlen(s));
	if (!ns)
		return (NULL);
	i = 0;
	while (*s)
	{
		ns[i] = (*f)(i, *s);
		s++;
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
