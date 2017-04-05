/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 22:35:45 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/30 00:32:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	tmp;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len / 2)
		{
			tmp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = tmp;
			i++;
		}
	}
	return (s);
}
