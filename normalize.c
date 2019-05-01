/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:38:00 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 11:59:35 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	normalize(t_tetri *tetri)
{
	int		i;
	int		j;
	int		jmin;

	tetri->height = tetri_height(tetri);
	tetri->width = tetri_width(tetri);
	i = 0;
	while (i < TETRI_SIZE)
	{
		if (ft_str_is_space

	}
	return (newshape);
}
