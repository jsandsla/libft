/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:59:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:03:59 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define E_OK 0
# define E_UNKNOW -1
# define E_MALLOC -2
# define E_INVALID_PARAMETER -3
# define E_OUT_OF_BOUNDS -4
# define E_OUT_OF_MEMORY -5

typedef int		t_err;

typedef unsigned char	t_byte;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_d
{
	size_t	len;
	size_t	max_len;
	size_t	reserve_len;
	t_byte	*ptr;
}				t_d;

typedef struct	s_da
{
	size_t	len;
	size_t	sz;
	void	*ptr;
	t_d		d;
}				t_da;

typedef struct	s_ds
{
	size_t	len;
	char	*ptr;
	t_d		d;
}				t_ds;

typedef struct	s_dd
{
	size_t	len;
	t_d		*ptr;
	t_da	da;
}				t_dd;

/*
** make; dep: -;
*/
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *lit, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strnlen(const char *s, size_t n);

size_t			ft_is_powof2(size_t val);
size_t			ft_next_powof2(size_t val);

/*
** make part2; dep: malloc, free, write;
*/
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** make list; dep: malloc, free;
*/
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

/*
** make d; dep: malloc, free;
*/
t_err			ft_dinit(t_d *d, t_byte *mem, size_t len);
t_err			ft_dexpand(t_d *d, size_t required);
t_err			ft_dappend(t_d *d, t_byte *mem, size_t len);
t_err			ft_dappendc(t_d *d, t_byte *mem, t_byte c, size_t len);
void			ft_dfree(t_d *d);

t_err			ft_dainit(t_da *arr, size_t sz, void *elems, size_t count);
t_err			ft_daappend(t_da *arr, void *elems, size_t count);
t_err			ft_daremove(t_da *arr, size_t i);
void			*ft_da(t_da *arr, size_t i);
void			ft_dafree(t_da *arr);

t_err			ft_dsinit(t_ds *str, char *mem, size_t max_len);
t_err			ft_dsappend(t_ds *str, char *mem, size_t n);
void			ft_dsfree(t_ds *str);

t_err			ft_ddinit(t_dd *dd);
t_err			ft_ddnewinit(t_dd *dd, t_d **ppd, t_byte *mem, size_t len);
t_err			ft_ddnew(t_dd *dd, t_d **ppd);
t_err			ft_ddappend(t_dd *dd, t_d *d);
t_err			ft_ddremove(t_dd *dd, size_t i);
void			ft_ddfree(t_dd *dd);

/*
** inline;
*/
# define FT_MIN(l, r) (l < r ? l : r)
# define FT_MAX(l, r) (l > r ? l : r)
# define FT_CLAMP(v, l, r) FT_MIN(r, FT_MAX(v, l))

/*
** ctype
*/
unsigned char	g_ctype_char_info[256] = {
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x95, 0x95, 0x95, 0x95, 0x95, 0x95,
	0x95, 0x95, 0x95, 0x95, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xD3,
	0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
	0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
	0x53, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
	0x9B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
	0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x10, 0x10, 0x10,
	0x10
};

# define IS_ALNUM(x) (g_ctype_char_info[x] & 1)
# define IS_ALPHA(x) (g_ctype_char_info[x] & 2)
# define IS_DIGIT(x) (g_ctype_char_info[x] & 4)
# define IS_LOWER(x) (g_ctype_char_info[x] & 8)
# define IS_PRINT(x) (g_ctype_char_info[x] & 16)
# define IS_SPACE(x) (g_ctype_char_info[x] & 32)
# define IS_UPPER(x) (g_ctype_char_info[x] & 64)
# define IS_XDIGIT(x) (g_ctype_char_info[x] & 128)

# define IS_ASCII(x) ((int)(char)(unsigned char)(x) > 0)

#endif
