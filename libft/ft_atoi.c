/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:33:29 by ahamouda          #+#    #+#             */
/*   Updated: 2015/12/01 22:15:26 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 0;
	result = 0;
	while (ft_isspace(*nptr) && *nptr)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr)
	{
		result *= 10;
		result += (*nptr - 48);
		nptr++;
	}
	if (sign)
		return (-result);
	return (result);
}
