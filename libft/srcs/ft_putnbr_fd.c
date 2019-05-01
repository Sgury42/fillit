/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:11:26 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:22:34 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_putnbr_rec_fd(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_rec_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == FT_INT_MIN)
	{
		ft_putstr_fd(FT_STR_INT_MIN, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = (n < 0 ? -n : n);
	}
	ft_putnbr_rec_fd(n, fd);
}
