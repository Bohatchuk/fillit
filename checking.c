/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:48:25 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/19 20:55:32 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_smsz(char *s, int n)
{
	size_t	i;
	int		*res;
	char	*et;

	res = (int*)ft_memalloc(2 * sizeof(int));
	i = 0;
	res[0] = 1;
	while (!(s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0')))
		i++;
	et = ft_strnew(i + 1);
	et = ft_strncpy(et, s, i + 1);
	s = s + i + 2;
	while (*s != '\0')
	{
		res[0] = ft_strnequ(et, s, i + 1);
		if (res[0] == 0 || ft_strlen(s) < i + 1)
			break ;
		s = s + i + 2;
	}
	res[1] = 0;
	while (res[1] * res[1] < n)
		res[1]++;
	return (res);
}

void	ft_clear(char *m, char cural)
{
	size_t	i;

	i = ft_strlen(m);
	while (i-- > 0)
		if (m[i] == cural)
			m[i] = '.';
}

int		ft_check(char *m, char *s, size_t sz)
{
	size_t bg;
	size_t ln;
	size_t i;

	bg = 0;
	while (m[bg] != '\0')
	{
		i = bg - 1;
		ln = -1;
		while (!(s[++ln] == '\n' && (s[ln + 1] == '\n' || s[ln + 1] == '\0')))
		{
			i++;
			if ((s[ln] == '#' && m[i] != '.') || m[i] == '\0')
				break ;
			if (s[ln] == '\n')
				i = bg + (sz + 1) * ((i - bg) / (sz + 1) + 1) - 1;
		}
		if (s[ln] == '\n' && (s[ln + 1] == '\n' || s[ln + 1] == '\0'))
			return ((int)bg);
		bg++;
	}
	return (-1);
}
