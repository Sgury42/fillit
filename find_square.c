/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 08:54:30 by sgury             #+#    #+#             */
/*   Updated: 2019/04/29 15:15:47 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_grid	*new_grid(t_grid *grid, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((grid = (char *)malloc(sizeof(t_grid))) == NULL)
		return (NULL);
	if ((grid->square = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	grid->size = size;
	while (i < size)
	{
		if ((square[i] = ft_strnew(size)) == NULL)
			return (NULL);
		while (j < size)
			square[i][j++] = '.';
		square[i][j] = '\0';
		j = 0;
		i++;
	}
	square[i] = 0;
	return (grid);
}

static int	is_placeable(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->height)
	{
		j = 0;
		while (j < tetri->width)
		{
			if (!(i + x < grid->size && j + y < grid->size))
				return (0);
			if (tetri->shape[i][j])
			{
				if (grid->square[x + i][y + j] != '.')
					return (0);
				grid->square[x + i][y + j] = tetri->shape[i][j];
			}
		}
	}
	return (1);
}

static int	fill_square(t_grid *grid, t_tetri **tetris, int nbtetris, int k)
{
	int	i;
	int j;

	if (k == nbtetris)
		return (1);
	i = 0;
	while (i < grid->size)
	{
		j = 0;
		while (j < grid->size)
		{
			if (is_placeable(grid, tetris[k], i, j))
				if (fill_square(grid, tetris, nbtetris, k + 1) == 1)
					return (1);
			remove_tetri(tetris[k]->letter);
		}
	}
	return (0);
}

t_grid	*fill_grid(t_tetri **tetri, t_grid *grid)
{
	int	tetri_count;
	int	square_min;

	tetri_count = 0;
	square_min = 2;
	while (tetris[tetri_count] != 0)
		tetri_count++;
	while ((square_min * square_min) < (tetri_count * 4))
		square_min++;
	if ((grid = new_grid(grid, square_min)) == NULL)
		return (NULL);
	while(!fill_square(tetri, grid))
	{
		del_grid(&grid);
		grid = new_grid(grid, ++square_min);
	}
	return (grid);
}
