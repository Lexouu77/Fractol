/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 05:49:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/18 13:35:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Realloc de la linee
*/

static char		gnl_realloc(char **line, int n_size)
{
	char	*n_line;

	if (n_size == BUFF_SIZE + 1)
	{
		if (((*line) = ((char *)malloc(sizeof(char) * n_size))) == NULL)
			return ('e');
		return ('o');
	}
	if ((n_line = ((char *)malloc(sizeof(char) * n_size))) == NULL)
		return ('e');
	ft_memmove(n_line, (*line), n_size - BUFF_SIZE + 1);
	free(*line);
	*line = n_line;
	return ('o');
}

/*
** Check si on a deja une lecture avec le fd actuel,
** sinon cree un nouveau maillon avec le fd passe en parametre
*/

static t_gnl	*gnl_select_fd(t_gnl **begin, int fd)
{
	t_gnl	*current_list;
	char	esc;

	current_list = *begin;
	esc = 'n';
	while (current_list != NULL && esc != 'y')
	{
		esc = (current_list->fd == fd ? 'y' : 'n');
		if (current_list->fd != fd)
			current_list = current_list->next;
	}
	if (current_list == NULL)
	{
		if ((current_list = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
			return (NULL);
		if ((current_list->buffer = ft_strnew(BUFF_SIZE - 1)) == NULL)
			return (NULL);
		current_list->fd = fd;
		current_list->start = 0;
		current_list->end = 0;
		current_list->next = *begin;
		*begin = current_list;
	}
	return (current_list);
}

/*
** Free un maillon avec le fd passe en parametre
*/

static void		gnl_free_fd(t_gnl **begin, int fd)
{
	t_gnl	*current_list;
	t_gnl	*to_free_list;

	current_list = *begin;
	if ((*begin)->next == NULL)
	{
		free((*begin)->buffer);
		free(*begin);
		*begin = NULL;
		return ;
	}
	if (current_list->fd == fd)
	{
		to_free_list = current_list;
		*begin = current_list->next;
	}
	else
	{
		while (current_list->next->fd != fd)
			current_list = current_list->next;
		to_free_list = current_list->next;
		current_list->next = current_list->next->next;
	}
	free(to_free_list->buffer);
	free(to_free_list);
}

/*
** read and stock
*/

static char		gnl_rx(t_gnl *current_fd, char **line, int *i, char lr)
{
	int	ret;

	if (current_fd->end - current_fd->start == 0)
	{
		if ((ret = read(current_fd->fd, current_fd->buffer, BUFF_SIZE)) == -1)
		{
			return ('e');
		}
		if (ret == 0)
			return ('f');
		current_fd->start = 0;
		current_fd->end = ret;
		if (lr == 'l')
			return ('L');
	}
	if (current_fd->buffer[current_fd->start] != '\n')
	{
		(*line)[(*i)++] = (current_fd->buffer)[current_fd->start];
		(*line)[*i] = '\0';
		(current_fd->start)++;
		return ('r');
	}
	(*line)[*i] = '\0';
	(current_fd->start)++;
	return ('L');
}

/*
** Si return de 'e' => ERROR
** Check si la lecture sur le fd est finie via gnl_select_fd
** Set ret_rx = 'r' for reading
** While r/lecture/lu, on lit
*/

int				get_next_line(const int fd, char **line)
{
	int				i;
	int				ret_rx;
	static t_gnl	*begin = NULL;
	t_gnl			*current_fd;

	i = 0;
	if (fd < 0 || !line || (current_fd = gnl_select_fd(&begin, fd)) == NULL)
		return (-1);
	ret_rx = 'r';
	while (ret_rx == 'r' || ret_rx == 'l')
	{
		if (i % BUFF_SIZE == 0 && ret_rx != 'l')
		{
			if (gnl_realloc(line, i + BUFF_SIZE + 1) == 'e')
				return (-1);
		}
		if ((ret_rx = gnl_rx(current_fd, line, &i, ret_rx)) == 'e')
			return (-1);
	}
	if (ret_rx == 'L')
		return (1);
	gnl_free_fd(&begin, fd);
	return (0);
}
