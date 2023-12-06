/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_42.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:05:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/12/06 00:32:24 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_42_H
# define LIB_42_H

# include "colors.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

typedef struct s_join
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	int				flag[2];
}				t_join;

int		ft_printchar(int fd, char c);
int		ft_printstr(int fd, char *c);
int		ft_printunsigned(int fd, int n);
int		ft_printnbr(int fd, int n);
int		ft_hex(int fd, int n, char flag);
int		ft_fprintf(int fd, const char *str, ...);
char	*get_next_line(int fd);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**free2d(char **str);
void	*ft_calloc(size_t nelem, size_t size);
char	**ft_split(char *str, char delim);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*join_em(char *s1, char *s2, int _free);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif