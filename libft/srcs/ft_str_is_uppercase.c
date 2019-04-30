/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:47:04 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/06 23:56:42 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_isupper(*s))
			return (0);
		s++;
	}
	return (1);
}