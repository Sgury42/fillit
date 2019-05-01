/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:28:20 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:17:42 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned int		nb;

	nb = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if (sign == -1 && nb > 2147483648)
			return (0);
		i++;
	}
	return (nb * sign);
}
