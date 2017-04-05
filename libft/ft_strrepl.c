/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:54:24 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/29 22:19:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepl(char *src, char to_find, char c)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] == to_find)
			src[i] = c;
		i++;
	}
	return (src);
}
