/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:08:00 by sgury             #+#    #+#             */
/*   Updated: 2019/04/27 11:17:50 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	fill_tab(char **tetri, int tetri_count, char *buff)
{
	int		i;
	int		j;
	int		b;
	char	letter;

	i = 0;
	j = 0;
	b = 0;
	letter = 'A';
	while (i < tetri_count)
	{
		if ((tetri[i] = (char *)malloc(sizeof(char) * (TETRI_SIZE))) == NULL)
			return (-1);
		while (j < TETRI_SIZE)
		{
			if (buff[b] == '#')
			{
				tetri[i][j++] = letter;
				b++;
			}
			else
				tetri[i][j++] = buff[b++];
		}
		if ((tetri_is_valid(tetri[i], i)) < 0)
			return (-1);
		b++;
		i++;
		letter++;
		j = 0;
	}
	tetri[i] = 0;
	return (1);
}

char	**split_file(char *file_name, char **tetri)
{
	int		fd;
	int		tetri_count;
	int		read_ret;
	char	buff[MAX_FILE + 1];

	fd = open(file_name, O_RDONLY);
	if ((read_ret = read(fd, buff, MAX_FILE + 1)) < 0)
		return (NULL);
	if (read_ret == MAX_FILE + 1)
		return (NULL);
	if (((read_ret + 1) % (TETRI_SIZE + 1)) != 0)
		return (NULL);
	tetri_count = (read_ret + 1) / (TETRI_SIZE + 1);
	if ((tetri = (char **)malloc(sizeof(char *) * (tetri_count + 1))) == NULL)
		return (NULL);
	if ((fill_tab(tetri, tetri_count, buff)) > 0)
		return (tetri);
	else
		return (NULL);
}
