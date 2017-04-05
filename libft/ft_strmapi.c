/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:27 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/26 00:17:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mappedstr;

	if (!s || !f)
		return (NULL);
	mappedstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mappedstr)
		return (NULL);
	i = -1;
	while (s[++i])
		mappedstr[i] = f(i, s[i]);
	mappedstr[i] = '\0';
	return (mappedstr);
}
