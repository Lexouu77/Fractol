/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:11:50 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/23 23:46:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char		*p_dest;
	const char	*p_src = src;

	p_dest = dest;
	while ((*p_dest++ = *p_src++))
		*p_dest = '\0';
	return (dest);
}
