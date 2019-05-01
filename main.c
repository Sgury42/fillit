/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:38:28 by sgury             #+#    #+#             */
/*   Updated: 2019/05/01 15:10:16 by pvinson          ###   ########.fr       */
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
		write(1, "error", 5);
		return (-1);
	}
	file_name = av[1];
	grid = NULL;
	if ((tetris = split_file(file_name)) == NULL)
		return (-1);
	if ((grid = fill_grid(tetris, grid)) == NULL)
		return (-1);
	ft_print_word_table(grid->square);
	return (0);
}
