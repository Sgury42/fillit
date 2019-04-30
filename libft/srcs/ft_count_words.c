/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:52:18 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/06 23:37:31 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(const char *s, char c)
{
	int		nbw;

	if (!s)
		return (0);
	nbw = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			nbw++;
		while (*s && *s != c)
			s++;
	}
	return (nbw);
}