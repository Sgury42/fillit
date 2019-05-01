/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:59:35 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:21:16 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstaddend(t_list **alst, t_list *newt)
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	if (!tmp)
		*alst = newt;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newt;
	}
}
