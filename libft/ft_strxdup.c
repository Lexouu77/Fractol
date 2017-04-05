/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 02:02:55 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/07 10:48:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strxdup(const char *s, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[len] != c || s[len])
		len++;
	dest = (char*)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = 0;
	return (dest);
}
