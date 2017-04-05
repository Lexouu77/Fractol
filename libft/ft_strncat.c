/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:30 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/06 20:20:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (n-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}
