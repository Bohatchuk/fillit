/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_except_symb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:01:15 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/16 16:01:27 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*strdup_except_symb(char *s, int size, char c)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] == '\n' && is_horizontal(s, (i - 4)))
			i++;
		else
		{
			res[j] = s[i];
			j++;
			i++;
		}
	}
	res[j] = '\0';
	return (res);
}
