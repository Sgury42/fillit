/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:54:17 by sgury             #+#    #+#             */
/*   Updated: 2019/05/01 17:08:12 by pvinson          ###   ########.fr       */
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
	if ((grid = (t_grid *)malloc(sizeof(t_grid))) == NULL)
		return (NULL);
	if ((grid->square = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	grid->size = size;
	while (i < size)
	{
		if ((grid->square[i] = ft_strnew(size)) == NULL)
			return (NULL);
		while (j < size)
			grid->square[i][j++] = '.';
		grid->square[i][j] = '\0';
		j = 0;
		i++;
	}
	grid->square[i] = 0;
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
			if (tetri->shape[i][j] == tetri->letter)
			{
				if (grid->square[x + i][y + j] != '.')
					return (0);
				grid->square[x + i][y + j] = tetri->shape[i][j];
			}
			j++;
		}
		i++;;
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
			remove_tetri(grid, tetris[k]->letter);
			j++;
		}
		i++;
	}
	return (0);
}

t_grid	*fill_grid(t_tetri **tetris, t_grid *grid)
{
	int	tetri_count;
	int	square_min;
	int	k;

	tetri_count = 0;
	square_min = 2;
	while (tetris[tetri_count] != 0)
		tetri_count++;
	while ((square_min * square_min) < (tetri_count * 4))
		square_min++;
	if ((grid = new_grid(grid, square_min)) == NULL)
		return (NULL);
	k = 0;
	while(!fill_square(grid, tetris, tetri_count, k))
	{
		del_grid(grid);
		grid = new_grid(grid, ++square_min);
	}
	return (grid);
}
