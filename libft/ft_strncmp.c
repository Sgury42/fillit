/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:27:37 by pvinson           #+#    #+#             */
/*   Updated: 2019/04/07 00:14:19 by pvinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (n == 0)
		return (0);
	if (i == n)
		i--;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
