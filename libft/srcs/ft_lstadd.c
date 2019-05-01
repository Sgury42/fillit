/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:54:38 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:21:16 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *newt)
{
	if (!alst)
		return ;
	else if (*alst)
		newt->next = *alst;
	*alst = newt;
}
