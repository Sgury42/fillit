/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:41:45 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:25:57 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_str_is_printable(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_isprint(*s))
			return (0);
		s++;
	}
	return (1);
}
