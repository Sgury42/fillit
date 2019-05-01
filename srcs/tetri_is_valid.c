/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:15:30 by sgury             #+#    #+#             */
/*   Updated: 2019/05/01 11:41:10 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	block_valid(char *tetri, char letter)
{
	int		j;
	int 	count_block;
	int		link;

	j = 0;
	count_block = 0;
	link = 0;
	while (tetri[j] != '\0')
	{
		while (tetri[j] == '.' || tetri[j] == '\n')
			j++;
		if (tetri[j] == letter)
		{
			count_block++;
			if (tetri[j + 1] == letter)
				link++;
			if (tetri[j + 5] == letter)
				link++;
			if (tetri[j - 1] == letter)
				link++;
			if (tetri[j - 5] == letter)
				link++;
			j++;
		}
	}
	if (count_block != 4 || j != 20 || (link != 6 && link != 8))
		return (-1);
	return (1);
}

static int	char_valid(char *tetri, char letter)
{
	int 	j;
	int		len;
	int 	height;

	j = 0;
	len = 0;
	height = 0;
	while (tetri[j] != '\0')
	{
		while (len < 4)
		{
			if (tetri[j] != '.' && tetri[j] != letter)
				return (-1);
			len++;
			j++;
		}
		if (len == 4 && tetri[j] != '\n')
			return (-2);
		len = 0;
		height++;
		j++;
		if (height == 4 && tetri[j] == '\0' && j == 20)
			return (1);
	}
	return (-1);
}

int	tetri_is_valid(char *tetri, char letter)
{

	if ((char_valid(tetri, letter)) > 0)
		if ((block_valid(tetri, letter)) > 0)
			return (1);
	return (-1);
}
