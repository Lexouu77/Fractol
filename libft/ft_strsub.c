/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:13:02 by ahamouda          #+#    #+#             */
/*   Updated: 2015/11/24 00:29:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ns;
	char *begin_ns;

	if (!s)
		return (NULL);
	ns = ft_strnew(len);
	if (!ns)
		return (NULL);
	begin_ns = ns;
	while (start--)
		s++;
	while (*s && len--)
		*ns++ = *s++;
	return (begin_ns);
}
