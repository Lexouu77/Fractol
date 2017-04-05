/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 00:37:50 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/07 10:48:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char*)malloc(sizeof(char) * n + 1);
	if (!dest)
		return (NULL);
	while (s[i] && n--)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
