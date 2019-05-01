/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:47:06 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:21:16 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!(alst))
		return ;
	if (del && *alst)
		(*del)((*alst)->content, (*alst)->content_size);
	if (*alst)
		free(*alst);
	*alst = NULL;
	alst = NULL;
}
