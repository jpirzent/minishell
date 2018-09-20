/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:32:10 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/20 15:46:02 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 8
# define UINT_MX 4294967296

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content, size_t content_size);
void		ft_putchar(char c);
void		ft_putstr(const char *s);
void		ft_memdel(void **as);
void		ft_strclr(char *s);
void		ft_strrev(char *s);
void		ft_putnbr(int n);
void		ft_putnbrl(long nbr);
void		ft_pudec(long l);
void		ft_putchex(long n);
void		ft_putcd(int i);
void		ft_putendl(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_strdel(char **as);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		ft_striter(char *s, void (*f)(char *));
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memalloc(size_t size);
void		ft_putbnbr(int base, long n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);

int			ft_strnequ(char const *s1, char const *s2, size_t n);
int			ft_isalpha(int c);
int			ft_strequ(char const *s1, char const *s2);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strchr_b(const char *s, const char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			get_next_line(int const fd, char **line);

size_t		ft_strlen(const char *str);

char		*ft_strtrim(const char *s);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_itoa(int a);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strncpy(char *dest, const char *src, size_t len);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strchr(const char *s, int c);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		**ft_strsplit(char const *s, char c);
char		**ft_strtok(char *s);
char		*ft_strnew(size_t size);
char		*ft_find_char(char *s, char c);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
