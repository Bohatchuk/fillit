/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:30:54 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/17 14:16:27 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sharp_touch(char *str, int i, int *touch)
{
	if (str[i] == '#')
	{
		if (i < 20 && str[i + 1] == '#')
			*touch = *touch + 1;
		if (i > 0 && str[i - 1] == '#')
			*touch = *touch + 1;
		if (i < 14 && str[i + 5] == '#')
			*touch = *touch + 1;
		if (i > 4 && str[i - 5] == '#')
			*touch = *touch + 1;
	}
}

int		is_tetrimino(char *str)
{
	int		i;
	int		touch;
	char	*start;

	i = 0;
	start = str;
	while (start[i] != '\0')
	{
		touch = 0;
		while (start[i] && i < 21)
		{
			sharp_touch(start, i, &touch);
			if ((((i + 1) % 5) == 0 || i == 20) && start[i] != '\n')
				ft_error();
			i++;
		}
		start = start + i;
		if (touch != 6 && touch != 8)
			ft_error();
		i = 0;
	}
	return (1);
}

void	check_symbol(char symb, int *dots, int *sharps, int *newlines)
{
	if (symb == '.')
		*dots = *dots + 1;
	else if (symb == '#')
		*sharps = *sharps + 1;
	else if (symb == '\n' || symb == '\0')
		*newlines = *newlines + 1;
}

int		count_elements(char *str)
{
	int		i;
	int		dots;
	int		sharps;
	int		newlines;
	char	*start;

	i = 0;
	start = str;
	while (start[i] != '\0')
	{
		start = start + 21 * ((i + 1) / 21);
		i = 0;
		dots = 0;
		sharps = 0;
		newlines = 0;
		while (i < 21)
		{
			check_symbol(start[i], &dots, &sharps, &newlines);
			i++;
		}
		if (dots != 12 || sharps != 4 || newlines != 5)
			ft_error();
		i--;
	}
	return (is_tetrimino(str));
}

int		validate(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			ft_error();
		i++;
	}
	if ((i + 1) % 21 != 0)
		ft_error();
	return (count_elements(str));
}
