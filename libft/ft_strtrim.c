/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:13:07 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/01 19:13:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblankspace(int c)
{
	return ((c == 32 || c == 9 || c == 10) ? 1 : 0);
}

static int	ft_isstrempty(char *s)
{
	size_t len;

	len = ft_strlen(s);
	while (ft_isblankspace(*s))
	{
		len--;
		s++;
	}
	return ((!len) ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char const		*begin_s = s;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	if (ft_isstrempty((char*)s))
		return (ft_strdup(""));
	while (*s && ft_isblankspace(*s))
	{
		start++;
		s++;
	}
	while (*s)
		s++;
	s--;
	while (*s && ft_isblankspace(*s))
	{
		end++;
		s--;
	}
	return (ft_strsub(begin_s, start, ft_strlen(begin_s) - start - end));
}
