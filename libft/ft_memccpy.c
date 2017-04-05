/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:36:23 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/25 22:20:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*p_dest;
	const char	*p_src = src;

	if (!dest || !src)
		return (NULL);
	p_dest = dest;
	while (n--)
	{
		*p_dest++ = *p_src;
		if (*p_src == c)
			return (p_dest);
		p_src++;
	}
	return (NULL);
}
