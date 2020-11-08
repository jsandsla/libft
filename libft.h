/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:59:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/07 16:48:33 by jsandsla         ###   ########.fr       */
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
# define E_INVALID_DATA_STRUCTURE -6

typedef int		t_err;

typedef unsigned char	t_byte;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_array
{
	size_t	len;
	size_t	max_len;
	size_t	sz;
	void	*ptr;
}				t_a;

typedef struct	s_string
{
	size_t	len;
	size_t	max_len;
	char	*ptr;
}				t_s;

typedef struct	s_dynamic
{
	size_t	len;
	size_t	max_len;
	size_t	reserve_len;
	t_byte	*ptr;
}				t_d;

typedef struct	s_dynamic_array
{
	t_a	a;
	t_d	*d;
	t_d	_d;
}				t_da;

typedef struct	s_dynamic_string
{
	t_s	s;
	t_d	*d;
	t_d	_d;
}				t_ds;

typedef struct	s_dynamic_dynamic
{
	size_t	len;
	t_d		*ptr;
	t_da	*da;
	t_da	_da;
}				t_dd;

typedef struct	s_dynamic_dynamic_string
{
	size_t	rate;
	t_dd	*dd;
	t_dd	_dd;
}				t_dds;

typedef struct	s_view_string
{
	size_t		len;
	size_t		offset;
	const char	*ptr;
}				t_vs;

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
char			*ft_strnchr(const char *s, int c, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *lit, size_t len);
size_t			ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strnlen(const char *s, size_t n);

size_t			ft_is_powof2(size_t val);
size_t			ft_next_powof2(size_t val);
size_t			ft_to_powof2(size_t val);

ssize_t			ft_max(ssize_t l, ssize_t r);
ssize_t			ft_min(ssize_t l, ssize_t r);

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
void			ft_ainit(t_a *a, size_t sz, void *mem, size_t max_len);
void			ft_ainitd(t_a *a, size_t sz, t_d *d);
size_t			ft_aappend(t_a *a, void *elems, size_t count);
size_t			ft_aappendd(t_a *a, t_d *d);
size_t			ft_aappenda(t_a *a, t_a *aa);
void			ft_aremove(t_a *a, size_t i);
void			ft_aremovep(t_a *a, void *p);
void			*ft_a(t_a *a, size_t i);

void			ft_sinit(t_s *s, char *str);
void			ft_sinitn(t_s *s, char *str, size_t n);
void			ft_sinitd(t_s *s, t_d *d);
void			ft_sinitm(t_s *s, void *mem, size_t n);
size_t			ft_sappend(t_s *s, const char *str);
size_t			ft_sappendn(t_s *s, const char *str, size_t n);
size_t			ft_sappendd(t_s *s, t_d *d);
size_t			ft_sappends(t_s *s, t_s *ss);
size_t			ft_sappendc(t_s *s, char c);
size_t			ft_scut(t_s *s, size_t offset, size_t len);
void			ft_sreverse(t_s *s, size_t offset, size_t len);
char			ft_s(t_s *s, size_t i);

t_err			ft_dinit(t_d *d, t_byte *mem, size_t len);
t_err			ft_dinitex(t_d *d, t_byte *mem, size_t len, size_t reserve_len);
t_err			ft_dexpand(t_d *d, size_t required);
t_err			ft_dappend(t_d *d, t_byte *mem, size_t len);
t_err			ft_dappendc(t_d *d, t_byte *mem, t_byte c, size_t len);
void			ft_dfree(t_d *d);

t_err			ft_dainit(t_da *da, size_t sz, void *elems, size_t max_len);
t_err			ft_dainitd(t_da *da, size_t sz, t_d *d);
t_err			ft_dainitdlink(t_da *da, size_t sz, t_d *d);
t_err			ft_daappend(t_da *da, void *elems, size_t count);
void			ft_daremove(t_da *da, size_t i);
t_err			ft_dalink(t_da *da, size_t sz, t_d *d);
void			*ft_da(t_da *da, size_t i);
void			ft_dafree(t_da *da);

t_err			ft_dsinit(t_ds *ds, char *mem, size_t len);
t_err			ft_dsinitd(t_ds *ds, t_d *d);
t_err			ft_dsinitdlink(t_ds *ds, t_d *d);
t_err			ft_dsappend(t_ds *ds, char *mem, size_t n);
t_err			ft_dslink(t_ds *ds, t_d *d);
void			ft_dsfree(t_ds *ds);

t_err			ft_ddinit(t_dd *dd);
t_err			ft_ddnew(t_dd *dd, t_d **ppd);
t_err			ft_ddnewinit(t_dd *dd, t_d **ppd, t_byte *mem, size_t len);
t_err			ft_ddnewinitex(t_dd *dd, t_d **ppd, t_byte *mem, size_t len,
	size_t reserve_len);
t_err			ft_ddappend(t_dd *dd, t_d *d);
void			ft_ddremove(t_dd *dd, size_t i);
t_err			ft_ddlink(t_dd *dd, t_da *da);
void			ft_ddfree(t_dd *dd);

t_err			ft_ddsinit(t_dds *dds, size_t rate);
t_err			ft_ddsappend(t_dds *dds, const char *str, size_t n);
t_err			ft_ddsappendstr(t_dds *dds, const char *str);
t_err			ft_ddsappendc(t_dds *dds, char c);
t_err			ft_ddsappends(t_dds *dds, t_s *s);
t_err			ft_ddsappendvs(t_dds *dds, t_vs *vs);
t_s				ft_dds(t_dds *dds, size_t i);
void			ft_ddsfree(t_dds *dds);
size_t			ft_dds_len(t_dds *dds);

t_vs			ft_vscreate(const char *str, size_t len);
t_vs			ft_vscreatestr(const char *str);
t_vs			ft_vscreateds(t_ds *ds, size_t offset, size_t len);
t_vs			ft_vscreates(t_s *s, size_t offset, size_t len);
t_vs			ft_vssub(t_vs *vs, size_t offset, size_t len);
char			ft_vsinc(t_vs *vs, size_t offset);
char			ft_vsincif(t_vs *vs, char c, size_t offset);
char			ft_vs(t_vs *vs, size_t offset);
void			ft_vsreset(t_vs *vs);
size_t			ft_vs_strtou(t_vs *vs, t_uint *out, int base, const char *sym);
size_t			ft_vs_strtol(t_vs *vs, int *out, int base, const char *sym);
size_t			ft_vs_read_uint(t_vs *vs, t_uint *out);
size_t			ft_vs_read_int(t_vs *vs, int *out);

# define FT_VS_SYMX "0123456789abcdef"
# define FT_VS_SYMBIGX "0123456789ABCDEF"

/*
** inline;
*/
# define FT_MIN(l, r) ((l) < (r) ? (l) : (r))
# define FT_MAX(l, r) ((l) > (r) ? (l) : (r))
# define FT_CLAMP(v, l, r) FT_MIN(r, FT_MAX(v, l))
# define FT_USUB(l, r) ((l) <= (r) ? 0 : (l) - (r))

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

# define IS_ASCII(x) ((char)(unsigned char)(x) >= 0)

#endif
