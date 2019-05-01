/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:51:30 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:21:16 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*ite;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	ite = *alst;
	while (ite)
	{
		tmp = ite->next;
		ft_lstdelone(&ite, del);
		ite = tmp;
	}
	*alst = NULL;
	alst = NULL;
}
