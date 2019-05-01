/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:23:11 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:19:13 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char			*snb;
	int				size;
	int				neg;
	unsigned int	tmp;

	neg = (n < 0 ? 1 : 0);
	size = (n == 0 ? 1 : 0);
	if (n == FT_INT_MIN)
		return (ft_strdup(FT_STR_INT_MIN));
	tmp = (n < 0 ? -n : n);
	while (tmp > 0 && ++size > 0)
		tmp /= 10;
	snb = ft_strnew(size + neg);
	if (!snb)
		return (NULL);
	snb[0] = (neg ? '-' : '0');
	snb[size + neg] = '\0';
	tmp = (n < 0 ? -n : n);
	while (size >= neg)
	{
		size--;
		snb[size + neg] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (snb);
}
