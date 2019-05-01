/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:46:07 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:25:45 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ns;
	unsigned int	i;

	if (!s)
		return (NULL);
	ns = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ns[i] = s[i + start];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
