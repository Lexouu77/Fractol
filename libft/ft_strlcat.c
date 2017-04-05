/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:16 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/01 22:12:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len_dest;
	size_t len_src;
	size_t size_origin;

	size_origin = size;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	while (*dest && size)
	{
		dest++;
		size--;
	}
	if (!size)
		return (size_origin + len_src);
	while (*src && size-- > 1)
		*dest++ = *src++;
	*dest = '\0';
	return (len_dest + len_src);
}
