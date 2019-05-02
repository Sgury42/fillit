/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:15:30 by sgury             #+#    #+#             */
/*   Updated: 2019/05/02 10:55:41 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_link(char **tetri, char letter, int i, int j)
{
	int	count_link;

	count_link = 0;
	if (j + 1 < TETRI_SIZE && tetri[i][j + 1] == letter)
		count_link++;
	if (i + 1 < TETRI_SIZE && tetri[i + 1][j] == letter)
		count_link++;
	if (j > 0 && tetri[i][j - 1] == letter)
		count_link++;
	if (i > 0 && tetri[i - 1][j] == letter)
		count_link++;
	return (count_link);
}

static int	block_valid(char **tetri, char letter)
{
	int	i;
	int	j;
	int	count_block;
	int	link;

	count_block = 0;
	link = 0;
	i = -1;
	while (++i < TETRI_SIZE)
	{
		j = -1;
		while (++j < TETRI_SIZE)
		{
			if (tetri[i][j] == letter)
			{
				count_block++;
				link += count_link(tetri, letter, i, j);
			}
		}
	}
	if (count_block != 4 || !(i == TETRI_SIZE && j == TETRI_SIZE)
			|| (link != 6 && link != 8))
		return (-1);
	return (1);
}

static int	char_valid(char **tetri, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (i < TETRI_SIZE)
	{
		j = 0;
		while (j < TETRI_SIZE)
		{
			if (tetri[i][j] != '.' && tetri[i][j] != letter)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int			tetri_is_valid(char **tetri, char letter)
{
	if ((char_valid(tetri, letter)) > 0)
		if ((block_valid(tetri, letter)) > 0)
			return (1);
	return (-1);
}
