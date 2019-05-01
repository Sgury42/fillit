/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:25:22 by pvinson           #+#    #+#             */
/*   Updated: 2019/05/01 17:00:03 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_COLOR_H
# define TETRI_COLOR_H

# define EOC				"\e[0m"

# define BC_RED				"\e[1;30;41m"
# define BC_GREEN			"\e[1;30;42m"
# define BC_YELLOW			"\e[1;30;43m"
# define BC_BLUE			"\e[1;30;44m"
# define BC_MAGENTA			"\e[1;30;45m"
# define BC_CYAN			"\e[1;30;46m"
# define BC_LIGHTGRAY		"\e[1;30;47m"
# define BC_DARKGRAY		"\e[1;30;100m"
# define BC_LIGHTRED 		"\e[1;30;101m"
# define BC_LIGHTGREEN		"\e[1;30;102m"
# define BC_LIGHTYELLOW 	"\e[1;30;103m"
# define BC_LIGHTBLUE 		"\e[1;30;104m"
# define BC_LIGHTMAGENTA 	"\e[1;30;105m"
# define BC_LIGHTCYAN 		"\e[1;30;106m"
# define BC_RED_I 			"\e[7;41m"
# define BC_GREEN_I 		"\e[7;42m"
# define BC_YELLOW_I 		"\e[7;43m"
# define BC_BLUE_I 			"\e[7;44m"
# define BC_MAGENTA_I 		"\e[7;45m"
# define BC_CYAN_I			"\e[7;46m"
# define BC_LIGHTGRAY_I		"\e[7;47m"
# define BC_DARKGRAY_I		"\e[7;100m"
# define BC_LIGHTRED_I		"\e[7;101m"
# define BC_LIGHTGREEN_I	"\e[7;102m"
# define BC_LIGHTYELLOW_I	"\e[7;103m"
# define BC_LIGHTBLUE_I		"\e[7;104m"
# define BC_LIGHTMAGENTA_I	"\e[7;105m"
# define BC_LIGHTCYAN_I		"\e[7;106m"

const char	*TETRI_COLOR[28] = {BC_RED, BC_GREEN, BC_YELLOW,
	BC_BLUE, BC_MAGENTA, BC_CYAN,
	BC_LIGHTGRAY, BC_LIGHTRED,
	BC_LIGHTGREEN, BC_LIGHTYELLOW, BC_LIGHTBLUE,
	BC_LIGHTMAGENTA, BC_LIGHTCYAN, BC_RED_I,
	BC_GREEN_I, BC_YELLOW_I, BC_BLUE_I,
	BC_MAGENTA_I, BC_CYAN_I, BC_LIGHTGRAY_I,
	BC_DARKGRAY_I, BC_LIGHTRED_I, BC_LIGHTGREEN_I,
	BC_LIGHTYELLOW_I, BC_LIGHTBLUE_I, BC_LIGHTMAGENTA_I,
	BC_LIGHTCYAN_I, BC_DARKGRAY};
	
# endif
