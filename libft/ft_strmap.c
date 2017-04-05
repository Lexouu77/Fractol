/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:12:23 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/26 00:16:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mappedstr;

	if (!s || !f)
		return (NULL);
	mappedstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mappedstr)
		return (NULL);
	i = -1;
	while (s[++i])
		mappedstr[i] = f(s[i]);
	mappedstr[i] = '\0';
	return (mappedstr);
}
