/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:36:27 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/24 01:00:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p_s = s;

	while (n--)
	{
		if (*p_s == (unsigned char)c)
			return ((void*)p_s);
		p_s++;
	}
	return (NULL);
}
