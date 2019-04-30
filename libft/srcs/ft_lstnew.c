/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:44:46 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/10 18:56:18 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*e;

	e = (t_list *)ft_memalloc(sizeof(t_list));
	if (!e)
		return (NULL);
	if (content)
	{
		e->content = ft_memalloc(content_size + 1);
		if (!e->content)
		{
			free(e);
			return (NULL);
		}
		ft_memmove(e->content, content, content_size + 1);
		e->content_size = content_size;
	}
	else
	{
		e->content = NULL;
		e->content_size = 0;
	}
	e->next = NULL;
	return (e);
}
