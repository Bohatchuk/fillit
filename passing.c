/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:48:34 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/20 13:06:50 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_pass(char *m, char *s, int st, char c)
{
	size_t	ln;
	int		i;
	int		bg;
	size_t	sz;

	sz = 0;
	while (m[sz] != '\n' && m[sz] != '\0')
		sz++;
	bg = st;
	i = st - 1;
	ln = 0;
	while (!(s[ln] == '\n' && (s[ln + 1] == '\n' || s[ln + 1] == '\0')))
	{
		i++;
		if (s[ln] == '\n')
		{
			st = st + (int)sz + 1;
			i = st;
			ln++;
		}
		if (s[ln] == '#')
			m[i] = c;
		ln++;
	}
	return (bg);
}

int		ft_move(char *m, char *s, char cural, size_t st)
{
	size_t ln;
	size_t i;
	size_t sz;

	sz = 0;
	while (m[sz] != '\n' && m[sz] != '\0')
		sz++;
	ft_clear(m, cural);
	while (m[++st] != '\0')
	{
		i = st - 1;
		ln = -1;
		while (!(s[++ln] == '\n' && (s[ln + 1] == '\n' || s[ln + 1] == '\0')))
		{
			i++;
			if ((s[ln] == '#' && m[i] != '.') || m[i] == '\0')
				break ;
			if (s[ln] == '\n')
				i = st + (sz + 1) * ((i - st) / (sz + 1) + 1) - 1;
		}
		if (s[ln] == '\n' && (s[ln + 1] == '\n' || s[ln + 1] == '\0'))
			return (ft_pass(m, s, (int)st, cural));
	}
	return (-1);
}

char	*ft_push(char *srs, char *s, int p)
{
	if (p > 0)
	{
		while (!(*srs == '\n' && (*(srs + 1) == '\n' || *(srs + 1) == '\0')))
			srs++;
		if (*(srs + 1) == '\n')
			srs = srs + 2;
	}
	else
	{
		while (--srs - 2 != s && !(*(srs - 1) == '\n' && *(srs - 2) == '\n'))
			;
		if (srs - 2 == s)
			srs = s;
	}
	return (srs);
}

int		ft_trypass(char *map, char *src, int *smsz, int tetnum)
{
	int		i;
	char	*s;
	int		*bg;

	bg = (int*)ft_memalloc(tetnum * (sizeof(int)));
	i = 0;
	s = src;
	bg[i] = ft_pass(map, src, bg[i], i + 65);
	src = ft_push(src, s, 1);
	while (bg[i] >= 0 && i++ >= 0 && i < tetnum)
	{
		if ((bg[i] = ft_check(map, src, smsz[1])) > -1)
		{
			bg[i] = ft_pass(map, src, bg[i], i + 65);
			src = ft_push(src, s, 1);
		}
		else if (smsz[0] == 0)
			while (bg[i] < 0 && --i > -1)
			{
				src = ft_push(src, s, -1);
				if ((bg[i] = ft_move(map, src, 65 + i, bg[i])) >= 0)
					src = ft_push(src, s, 1);
			}
	}
	return (i - tetnum);
}

char	*ft_fillit(char *src, int tetnum)
{
	int		i;
	int		*smsz;
	char	*table;
	int		bl;

	table = NULL;
	smsz = ft_smsz(src, 4 * tetnum);
	bl = -1;
	while (bl < 0)
	{
		ft_memdel((void**)(&table));
		table = ft_strnew(((size_t)smsz[1] + 1) * (size_t)smsz[1]);
		i = -1;
		while (++i < smsz[1] * (smsz[1] + 1))
		{
			if ((i + 1) % (smsz[1] + 1) == 0)
				table[i] = '\n';
			else
				table[i] = '.';
		}
		if ((bl = ft_check(table, src, smsz[1])) > -1)
			bl = ft_trypass(table, src, smsz, tetnum);
		smsz[1]++;
	}
	return (table);
}
