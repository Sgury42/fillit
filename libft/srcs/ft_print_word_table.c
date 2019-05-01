/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:05:37 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:22:34 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_word_table(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	while (split[++i])
		ft_putendl(split[i]);
}
