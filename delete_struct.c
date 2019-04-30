/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 08:51:57 by sgury             #+#    #+#             */
/*   Updated: 2019/04/30 09:00:04 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_grid(t_grid *grid)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
			free(grid->square[i][j++]);
		i++;
	}
	free(grid->size);
}

void	del_tetri(t_tetri **tetris)
{
	int	k;
	int	j;
	int	i;

	k = 0;
	i = 0;
	while (tetris[k] != 0)
	{
		j = 0;
		while (i < TETRI_SIZE)
		{
			while (j < TETRI_SIZE)
				free(tetris->shape[i][j++]);
			i++;
		}
		free(tetris->height);
		free(tetris->width);
		free(tetris->letter);
		k++;
	}
}
