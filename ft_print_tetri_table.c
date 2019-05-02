/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:05:37 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/02 14:49:52 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri_color.h"

void	ft_print_tetri_table(char **split)
{
	int	i;
	int	j;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] >= 'A' && split[i][j] <= 'Z')
			{
				ft_putstr(g_tetri_color[(split[i][j]) % 13]);
				ft_putchar(split[i][j]);
				ft_putstr(EOC);
			}
			else
				ft_putchar(split[i][j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
}
