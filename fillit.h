/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:46:46 by sgury             #+#    #+#             */
/*   Updated: 2019/04/29 14:58:05 by sgury            ###   ########.fr       */
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

char	**split_file(char *file_name, char **tetri);
int		tetri_is_valid(char *tetri, int i);
char	**find_square(char **tetri, char **square);

#endif
