/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 08:51:57 by sgury             #+#    #+#             */
/*   Updated: 2019/05/02 14:15:35 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	del_grid(t_grid *grid)
{
	int	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (i < grid->size)
	{
		free(grid->square[i]);
		i++;
	}
	free(grid->square[i]);
	free(grid->square);
	free(grid);
	grid = NULL;
}

void	del_tetri(t_tetri **tetris)
{
	int	k;
	int	i;

	k = 0;
	if (tetris == NULL)
		return ;
	while (tetris[k] != 0)
	{
		i = 0;
		while (i < TETRI_SIZE)
		{
			free(tetris[k]->shape[i]);
			i++;
		}
		free(tetris[k]->shape);
		free(tetris[k]);
		k++;
	}
	free(tetris);
	tetris = NULL;
}

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
