/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:31:53 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/07 01:11:33 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			tmp;

	j = ft_strlen(s) - 1;
	i = 0;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		++i;
		--j;
	}
}
