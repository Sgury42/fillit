/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:06:18 by sgury             #+#    #+#             */
/*   Updated: 2019/04/29 17:14:20 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(t_grid *grid, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (grid->square[i] != 0)
	{
		j = 0;
		while (grid->square[i][j] != '\0')
		{
			if (grid->square[i][j] == letter)
				grid->square[i][j] = '.';
			j++;
		}
		i++;
	}
}
