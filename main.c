/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:38:28 by sgury             #+#    #+#             */
/*   Updated: 2019/04/27 11:17:39 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int main(int ac, char **av)
{
	char    *file_name;
	char    **tetri;
	char    **square;

	if (ac != 2)
		write(1, "error", 5);
	file_name = av[1];
	tetri = NULL;
	square = NULL;
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
	if ((tetri = split_file(file_name, tetri)) == NULL)
		return (-1);
	ft_put_wrd_tab(tetri, "\n");
	if ((square = find_square(tetri, square)) == NULL)
		return (-1);
	ft_put_wrd_tab(square, "\n");
//	int	i;
//	i = 0;
//	while (tetri[i] != 0)
//	{
//		ft_putnbr(tetri_is_valid(tetri[i], i));
//		i++;
//	}
	return (0);
}
