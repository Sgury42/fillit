/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:38:28 by sgury             #+#    #+#             */
/*   Updated: 2019/05/01 17:48:17 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	char   		*file_name;
	t_tetri		**tetris;
	t_grid		*grid;

	if (ac != 2)
	{
		ft_usage();
		return (-1);
	}
	file_name = av[1];
	grid = NULL;
	if ((tetris = split_file(file_name)) == NULL)
	{
		ft_error();
		del_tetri(tetris);
		return (-1);
	}
	if ((grid = fill_grid(tetris, grid)) == NULL)
	{
		del_tetri(tetris);
		del_grid(grid);
		ft_error();
		return (-1);
	}
	ft_print_word_table(grid->square);
	del_grid(grid);
	del_tetri(tetris);
	return (0);
}
