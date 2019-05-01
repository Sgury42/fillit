/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:39:08 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/06 23:42:49 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*b;
	unsigned int	i;

	if (size == 0)
		return (NULL);
	b = malloc(size);
	if (!b)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)b)[i] = 0;
		i++;
	}
	return (b);
}
