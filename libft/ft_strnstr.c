/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:49 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/24 00:19:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *s_to_find, size_t n)
{
	size_t len;

	len = ft_strlen(s_to_find);
	if (!len)
		return ((char *)s);
	while (*s && len <= n--)
		if (!ft_memcmp(s++, s_to_find, len))
			return ((char *)s - 1);
	return (NULL);
}
