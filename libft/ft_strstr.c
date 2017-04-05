/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:59 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/24 00:29:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *s_to_find)
{
	int len;

	len = ft_strlen(s_to_find);
	if (!len)
		return ((char *)s);
	while (*s)
		if (!ft_memcmp(s++, s_to_find, len))
			return ((char *)s - 1);
	return (NULL);
}
