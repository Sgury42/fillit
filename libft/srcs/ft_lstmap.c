/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:59:29 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:20:11 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	nlst = (NULL);
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		ft_lstaddend(&nlst, (*f)(new));
		lst = lst->next;
	}
	return (nlst);
}
