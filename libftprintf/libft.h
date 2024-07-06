/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:50:43 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/11 07:21:31 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int			ft_isalpha(int a);
int			ft_isdigit(int a);
int			ft_isalnum(int a);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_strlen(char const *str);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_bzero(void *s, int n);
void		*ft_memcpy(void *d, const void *s, int n);
void		*ft_memmove(void *d, const void *s, unsigned long n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void	*s, int c, int n);
int			ft_memcmp(const void *s1, const void *s2, unsigned int n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *s);
void		*ft_calloc(int nmemb, int size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int		ft_printchar(int c);
void		ft_putstr(char *s);
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);
int		ft_printf(const char *str, ...);
int		ft_printptr(void *ptr);
int		ft_printnbrhex(unsigned int n);
int		ft_printnbr_u(long int nbr);
int		ft_printnbrhex_upper(unsigned int n);
int		ft_printnbrhexa_long(unsigned long int n);

#endif /* __LIBFT_H__ */
