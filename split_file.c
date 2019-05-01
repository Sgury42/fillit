/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:08:00 by sgury             #+#    #+#             */
/*   Updated: 2019/05/01 11:51:39 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	init_tetri(t_tetri *tetri)
{
	int i;

	if ((tetri = (t_tetri *)malloc(sizeof(t_tetri))) == NULL)
		return (0);
	if ((tetri->shape = (char **)malloc(sizeof(char *) * TETRI_SIZE + 1)) == NULL)
		return (0);
	i = 0;
	while (i < TETRI_SIZE)
	{
		if ((tetri->shape[i] = ft_strnew(TETRI_SIZE)) == NULL)
			return (0);
		i++;
	}
	return (1);
}

static int	fill_tab(t_tetri **tetris, int tetri_count, char *buff)
{
	int		k;
	int		i;
	int		j;
	int		b;
	char	letter;

	k = 0;
	b = 0;
	letter = 'A';
	while (k < tetri_count)
	{
		if (!init_tetri(tetris[k]))
			return (-1);
		i = 0;
		while (i < TETRI_SIZE)
		{
			j = 0;
			while (j < TETRI_SIZE)
			{
				if (buff[b] == '#')
					tetris[k]->shape[i][j] = letter;
				if (buff[b] != '\n')
					j++;
				b++;
			}
			if (buff[b] != '\n')
				i++;
			b++;
		}
		if ((tetri_is_valid(*tetris[k]->shape, tetris[k]->letter)) < 0)
			return (-1);
		b++;
		k++;
		letter++;
	}
	tetris[k] = 0;
	return (1);
}

t_tetri	**split_file(char *file_name, t_tetri **tetris)
{
	int		fd;
	int		tetri_count;
	int		read_ret;
	char	buff[MAX_FILE + 1];

	fd = open(file_name, O_RDONLY);
	if ((read_ret = read(fd, buff, MAX_FILE + 1)) < 0
			|| read_ret == MAX_FILE + 1
			|| ((read_ret + 1) % (TETRI_SIZE + 1)) != 0)
		return (NULL);
	tetri_count = (read_ret + 1) / (TETRI_SIZE + 1);
	if ((tetris = (t_tetri **)malloc(sizeof(t_tetri *) * (tetri_count + 1))) == NULL)
		return (NULL);
	if ((fill_tab(tetris, tetri_count, buff)) > 0)
		return (tetris);
	return (NULL);
}
