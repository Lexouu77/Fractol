/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:52 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/25 20:29:22 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_occ;

	last_occ = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			last_occ = (char *)s;
		s++;
	}
	if (!*s && *s == (char)c)
		last_occ = (char *)s;
	return ((last_occ) ? last_occ : NULL);
}
