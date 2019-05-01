/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:04:20 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:22:34 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_putnbr_rec(int n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_rec(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void			ft_putnbr(int n)
{
	if (n == FT_INT_MIN)
	{
		ft_putstr(FT_STR_INT_MIN);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = (n < 0 ? -n : n);
	}
	ft_putnbr_rec(n);
}
