/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:46:46 by sgury             #+#    #+#             */
/*   Updated: 2019/04/30 19:50:24 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# define MAX_FILE 545
# define TETRI_SIZE 4
# define NB_TETRI_MAX 26

typedef struct	s_grid {
	char		**square;
	int			size;
}				t_grid;

typedef struct	s_tetri {
	char		**shape;
	int			height;
	int			width;
	char		letter;
}				t_tetri;

t_tetri	**split_file(char *file_name, t_tetri **tetris);
int		tetri_is_valid(char *tetri, char letter);
t_grid	*fill_grid(t_tetri **tetris, t_grid *grid);
void	remove_tetri(t_grid *grid, char letter);
void	del_tetri(t_tetri **tetris);
void	del_grid(t_grid *grid);

#endif
