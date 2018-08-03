/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:32:12 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/18 13:46:43 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*buf;
	char	*str;
	int		size;

	buf = NULL;
	str = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file_with_tetriminos\n");
		exit(0);
	}
	buf = open_and_read_file(argv[1]);
	if (validate(buf) == 1)
		str = cut_tetriminos(buf);
	size = count_tetriminos(str);
	ft_putstr(ft_fillit(str, size));
	return (0);
}
