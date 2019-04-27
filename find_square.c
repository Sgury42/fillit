/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 08:54:30 by sgury             #+#    #+#             */
/*   Updated: 2019/04/27 11:24:29 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static char	**new_square(char **square, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((square = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		if ((square[i] = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
		while (j < size)
			square[i][j++] = '.';
		square[i][j] = '\0';
		j = 0;
		i++;
	}
	square[i] = 0;
	return (square);
}
/*
static int	fill_square(char **square, char **tetri)
{
}
*/
char	**find_square(char **tetri, char **square)
{
	int	tetri_count;
	int	square_min;

	tetri_count = 0;
	square_min = 2;
	while (tetri[tetri_count] != 0)
		tetri_count++;
	while ((square_min * square_min) < (tetri_count * 4))
		square_min++;
	if ((square = new_square(square, square_min)) == NULL)
		return (NULL);
//	if ((fill_square(square, tetri)) < 0)
//		return (NULL);
	return (square);
}
