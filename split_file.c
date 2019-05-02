/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:08:00 by sgury             #+#    #+#             */
/*   Updated: 2019/05/02 15:04:24 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void		init_value(t_tetri *tetri, char letter)
{
	tetri->letter = letter;
	tetri->height = TETRI_SIZE;
	tetri->width = TETRI_SIZE;
}

static t_tetri	**init_tetri(t_tetri **tetris, int tetri_count)
{
	int		i;
	int		k;
	char	letter;

	letter = 'A';
	k = -1;
	while (++k < tetri_count)
	{
		if (((tetris[k] = (t_tetri *)malloc(sizeof(t_tetri))) == NULL)
				|| ((tetris[k]->shape = (char **)
						malloc(sizeof(char *) * (TETRI_SIZE + 1))) == NULL))
			return (NULL);
		init_value(tetris[k], letter++);
		i = -1;
		while (++i < TETRI_SIZE)
		{
			if ((tetris[k]->shape[i] = ft_strnew(TETRI_SIZE)) == NULL)
				return (NULL);
			ft_memset(tetris[k]->shape[i], '.', TETRI_SIZE);
		}
		tetris[k]->shape[i] = NULL;
	}
	tetris[k] = 0;
	return (tetris);
}

static int		fill_tab(t_tetri **tetris, int tetri_count, char *buff)
{
	int		k;
	int		i;
	int		j;
	int		b;

	b = 0;
	k = -1;
	while (++k < tetri_count)
	{
		i = -1;
		while (++i < TETRI_SIZE)
		{
			j = -1;
			while (++j < TETRI_SIZE)
				if (buff[b++] == '#')
					tetris[k]->shape[i][j] = tetris[k]->letter;
			b++;
		}
		if ((buff[b] != '\n' && buff[b] != '\0')
				|| ((tetri_is_valid(tetris[k]->shape, tetris[k]->letter)) < 0)
				|| (normalize(tetris[k]) == -1))
			return (-1);
		b++;
	}
	return (1);
}

t_tetri			**split_file(char *file_name)
{
	t_tetri	**tetris;
	int		fd;
	int		tetri_count;
	int		read_ret;
	char	buff[MAX_FILE + 1];

	fd = open(file_name, O_RDONLY);
	if ((read_ret = read(fd, buff, MAX_FILE + 1)) < 0
			|| read_ret == MAX_FILE + 1
			|| ((read_ret + 1) % (TETRI_SIZE * (TETRI_SIZE + 1) + 1)) != 0)
		return (NULL);
	tetri_count = (read_ret + 1) / ((TETRI_SIZE) * (TETRI_SIZE + 1) + 1);
	if ((tetris = (t_tetri **)malloc(sizeof(t_tetri *) * (tetri_count + 1)))
		&& ((tetris = init_tetri(tetris, tetri_count)))
		&& ((fill_tab(tetris, tetri_count, buff)) > 0))
		return (tetris);
	del_tetri(tetris);
	return (NULL);
}
