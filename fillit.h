/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:36:17 by dbohatch          #+#    #+#             */
/*   Updated: 2017/12/17 19:20:03 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BUF_SIZE 545

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	*ft_memalloc(size_t size);
size_t	ft_strlen(const char *str);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_error(void);
char	*open_and_read_file(char *str);
int		validate(char *str);
int		count_elements(char *str);
void	check_symbol(char symb, int *dots, int *sharps, int *newlines);
int		is_tetrimino(char *str);
void	sharp_touch(char *str, int i, int *touch);
char	*cut_tetriminos(char *s);
char	*change_dots(char *s);
int		is_vertical(char *s, int i);
int		is_horizontal(char *s, int i);
int		count_len_and_symb(char *s);
char	*strdup_except_symb(char *s, int size, char c);
int		count_tetriminos(char *s);
size_t	fsize(char *s);
int		ft_check(char *m, char *s, size_t sz);
int		ft_pass(char *m, char *s, int st, char c);
int		ft_move(char *m, char *s, char cural, size_t sz);
char	*ft_push(char *srs, char *s, int p);
int		ft_trypass(char *map, char *src, int *smsz, int tetnum);
char	*ft_fillit(char *src, int tetnum);
int		*ft_smsz(char *s, int n);
char	*ft_strdup(const char *s1);
void	ft_clear(char *m, char cural);

#endif
