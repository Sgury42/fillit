/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:38:28 by sgury             #+#    #+#             */
/*   Updated: 2019/05/01 11:41:15 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	char   		*file_name;
	t_tetri		*tetris[NB_TETRI_MAX];
	t_grid		*grid;

	if (ac != 2)
	{
		write(1, "error", 5);
		return (-1);
	}
	file_name = av[1];
	grid = NULL;
	/*
	if (tetri = split_file(file_name, tetri))
		if (tetri_is_valid(tetri))
			if (find_square(tetri, square))
			{
				ft_putstr(square);
				return (0);
			}
	return (ft_putstr("error"));
	*/
	if ((split_file(file_name, tetris)) == NULL)
		return (-1);
	//ft_put_wrd_tab(tetris, "\n");
	if ((grid = fill_grid(tetris, grid)) == NULL)
		return (-1);
	//ft_put_wrd_tab(square, "\n");
//	int	i;
//	i = 0;
//	while (tetri[i] != 0)
//	{
//		ft_putnbr(tetri_is_valid(tetri[i], i));
//		i++;
//	}
	return (0);
}
