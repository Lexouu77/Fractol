/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:16:51 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/10 15:32:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_malloc_error(void)
{
	ft_putendl("Error : Memory Allocation Failed. Retry with more rights!");
	exit(-1);
}
