/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:38:00 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/02 09:36:37 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_trim_tab(t_tetri *tetri)
{
	int i;
	int j;
	int	jmin;

	jmin = TETRI_SIZE;
	i = 0;
	while (i < TETRI_SIZE)
	{
		j = -1;
		while (++j < TETRI_SIZE)
			if (tetri->shape[i][j] == tetri->letter)
				jmin = (j < jmin ? j : jmin);
		i++;
	}
	i = 0;
	while (i < TETRI_SIZE)
	{
		ft_memmove(tetri->shape[i], tetri->shape[i] + jmin, TETRI_SIZE - jmin);
		ft_memset(tetri->shape[i] + TETRI_SIZE - jmin, '.', jmin);
		i++;
	}
	return (1);
}

int		ft_empty_sort(t_tetri *tetri)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < TETRI_SIZE)
	{
		j = 0;
		while (j < TETRI_SIZE)
		{
			if (j < TETRI_SIZE - 1
					&& ft_strchr(tetri->shape[j], tetri->letter) == 0)
			{
				tmp = tetri->shape[j];
				tetri->shape[j] = tetri->shape[j + 1];
				tetri->shape[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		tetri_height(t_tetri *tetri)
{
	int i;
	int j;
	int	imin;
	int imax;

	imin = TETRI_SIZE;
	imax = 0;
	i = -1;
	while (++i < TETRI_SIZE)
	{
		j = -1;
		while (++j < TETRI_SIZE)
			if (tetri->shape[i][j] == tetri->letter)
			{
				imin = (i < imin ? i : imin);
				imax = (i > imax ? i : imax);
			}
	}
	return (imax - imin + 1);
}

int		tetri_width(t_tetri *tetri)
{
	int i;
	int j;
	int	jmin;
	int jmax;

	jmin = TETRI_SIZE;
	jmax = 0;
	i = -1;
	while (++i < TETRI_SIZE)
	{
		j = -1;
		while (++j < TETRI_SIZE)
			if (tetri->shape[i][j] == tetri->letter)
			{
				jmin = (j < jmin ? j : jmin);
				jmax = (j > jmax ? j : jmax);
			}
	}
	return (jmax - jmin + 1);
}

int		normalize(t_tetri *tetri)
{
	tetri->height = tetri_height(tetri);
	tetri->width = tetri_width(tetri);
	if (ft_empty_sort(tetri) == -1)
		return (-1);
	ft_trim_tab(tetri);
	return (1);
}
