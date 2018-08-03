/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:04 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/20 12:45:13 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_horizontal(char *s, int i)
{
	if ((i == 0 || s[i - 1] == '\n') && (s[i] == '.' || s[i] == '*') &&
		(s[i + 1] == '.' || s[i + 1] == '*') && (s[i + 2] == '.' ||
			s[i + 2] == '*') && (s[i + 3] == '.' || s[i + 3] == '*') &&
				(s[i + 4] == '\n' || s[i + 4] == '\0'))
		return (1);
	else
		return (0);
}

int		is_vertical(char *s, int i)
{
	if (i >= 0 && i <= 3 && (s[i] == '.' || s[i] == '*') && (s[i + 5] == '.' ||
		s[i + 5] == '*') && (s[i + 10] == '.' || s[i + 10] == '*') &&
		(s[i + 15] == '.' || s[i + 15] == '*'))
		return (1);
	else
		return (0);
}

char	*change_dots(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < 21)
	{
		if (is_horizontal(s, i))
		{
			s[i] = '*';
			s[i + 1] = '*';
			s[i + 2] = '*';
			s[i + 3] = '*';
		}
		if (is_vertical(s, i))
		{
			s[i] = '*';
			s[i + 5] = '*';
			s[i + 10] = '*';
			s[i + 15] = '*';
		}
		i++;
	}
	return (s);
}

int		count_len_and_symb(char *s)
{
	int		len;
	int		stars;
	int		size;

	len = 0;
	stars = 0;
	while (s[len] != '\0')
	{
		if (s[len] == '*')
			stars++;
		else if (s[len] == '\n' && is_horizontal(s, (len - 4)))
			stars++;
		len++;
	}
	size = len - stars;
	return (size);
}

char	*cut_tetriminos(char *s)
{
	char	*start;
	char	*str;
	int		i;
	int		size;

	i = 0;
	start = s;
	while (start[i] != '\0')
	{
		while (start[i] && i < 21)
		{
			change_dots(start);
			i++;
		}
		start = start + i;
		i = 0;
	}
	size = count_len_and_symb(s);
	str = strdup_except_symb(s, size, '*');
	return (str);
}
