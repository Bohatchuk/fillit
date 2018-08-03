/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:46:48 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/17 14:00:49 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*open_and_read_file(char *str)
{
	int		fd;
	int		len;
	char	buf[BUF_SIZE + 1];
	char	*s;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	len = read(fd, buf, BUF_SIZE);
	if (len == -1 || len > 545)
		ft_error();
	buf[len] = '\0';
	close(fd);
	s = ft_strdup(buf);
	return (s);
}
