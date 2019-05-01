/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:56:12 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:25:45 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ns)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ns[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ns[i] = *s2;
		s2++;
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
