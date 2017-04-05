/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:13 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/23 23:46:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ns;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		ns = ft_strnew(i);
		if (ns)
		{
			ns = ft_strcpy(ns, s1);
			ns = ft_strcat(ns, s2);
			return (ns);
		}
	}
	return (NULL);
}
