/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:42:30 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:25:45 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned int	i;

	s = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = '\0';
		++i;
	}
	s[i] = '\0';
	return (s);
}
