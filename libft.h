/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:59:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/02 17:28:56 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>

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

typedef struct	s_memory
{
	size_t	sz;
	size_t	len;
	size_t	cap;
	t_byte	*ptr;
}				t_m;

typedef struct	s_array
{
	t_m		*m;
	t_m		local_m;
}				t_a;

typedef struct	s_string
{
	t_m		*m;
	t_m		local_m;
}				t_s;

typedef struct	s_dynamic
{
	t_m		*m;
	t_m		local_m;
}				t_d;

typedef struct	s_dynamic_array
{
	t_a		a;
}				t_da;

typedef struct	s_dynamic_string
{
	t_s		s;
}				t_ds;

typedef struct	s_dynamic_dynamic
{
	size_t	len;
	t_d		*ptr;
	t_da	*da;
	t_da	local_da;
}				t_dd;

typedef struct	s_dynamic_dynamic_string
{
	size_t	rate;
	t_dd	dd;
}				t_dds;

typedef struct	s_view_string
{
	size_t		len;
	size_t		offset;
	const char	*ptr;
}				t_vs;

typedef float	t_v3[3];
typedef float	t_v4[4];
/*
** n x m : n - column index; m - row index;
*/
typedef float	t_m3[3][3];
typedef float	t_m4[4][4];

typedef float	t_quat[4];

typedef struct	s_ray
{
	t_v3	ori;
	t_v3	dir;
	float	hit;
	t_v3	hitnormal;
}				t_ray;

/*
** make; dep: -;
*/
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memset4(void *s, unsigned int c, size_t count);
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

typedef union	u_ieee754
{
	uint64_t	u;
	double		f;
}				t_ieee754;

typedef union	u_ieee754f
{
	uint32_t	u;
	float		f;
}				t_ieee754f;

int				ft_isnan(double f);
int				ft_isinf(double f);
double			ft_fpow(double f, size_t power);
double			ft_fabs(double f);
int				ft_epsilon(double diff, double epsilon);
double			ft_modf(double f, double *i);
double			ft_modf_rounded(double f, double *i, size_t precision);
double			ft_modf_erounded(double x, double *int_part, size_t precision);
double			ft_sqrt(double x);
float			ft_sqrtf(float x);

int				ft_dtostr(char *out, int n, double d);

float			ft_fabsf(float f);
int				ft_epsf(float diff, float epsilon);
float			ft_copysignf(float x, float y);

/*
** make part1; dep: malloc, free;
*/
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** make fd; dep: write
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putstr(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putendl(const char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putfloat_fd(float n, int fd);
void			ft_putfloat(float n);

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
void			ft_minit(t_m *m, size_t sz, void *mem, size_t len);
size_t			ft_mwrite(t_m *m, size_t offset, void *mem, size_t len);
size_t			ft_mwriteb(t_m *m, size_t offset, t_byte b);
size_t			ft_mappend(t_m *m, void *mem, size_t len);
size_t			ft_mappendm(t_m *m, t_m *mm);
size_t			ft_mappendb(t_m *m, t_byte b);
size_t			ft_mmove(t_m *m, void *mem, size_t len);
size_t			ft_mcut(t_m *m, size_t offset, size_t len);
void			*ft_m(t_m *m, size_t offset);

void			ft_ainit(t_a *a, size_t sz, void *mem, size_t cap);
void			ft_ainitm(t_a *a, t_m *m);
size_t			ft_aappend(t_a *a, void *elems, size_t count);
size_t			ft_aappendm(t_a *a, t_m *m);
void			ft_aremove(t_a *a, size_t i);
void			ft_aremovep(t_a *a, void *p);
void			*ft_a(t_a *a, size_t i);

void			ft_sinit(t_s *s, char *str);
void			ft_sinitn(t_s *s, char *str, size_t n);
void			ft_sinitm(t_s *s, t_m *m);
void			ft_sinitraw(t_s *s, void *mem, size_t cap);
size_t			ft_sappend(t_s *s, const char *str);
size_t			ft_sappendn(t_s *s, const char *str, size_t n);
size_t			ft_sappendraw(t_s *s, const char *str, size_t n);
size_t			ft_sappendc(t_s *s, char c);
size_t			ft_sappendm(t_s *s, t_m *m);
size_t			ft_smove(t_s *s, void *mem, size_t cap);
size_t			ft_scut(t_s *s, size_t offset, size_t len);
void			ft_sreverse(t_s *s, size_t offset, size_t len);
char			ft_s(t_s *s, size_t i);
size_t			ft_s_utoa(t_s *s, size_t n, unsigned base, const char *sym);
size_t			ft_s_itoa(t_s *s, ssize_t n, unsigned base, const char *sym);
size_t			ft_s_unsigned(t_s *s, size_t val);
size_t			ft_s_signed(t_s *s, ssize_t val);

t_err			ft_dinit(t_d *d, t_byte *mem, size_t len);
void			ft_dinitm(t_d *d, t_m *m);
t_err			ft_dexpand(t_d *d, size_t required);
t_err			ft_dappend(t_d *d, t_byte *mem, size_t len);
t_err			ft_dappendm(t_d *d, t_m *m);
void			ft_dfree(t_d *d);

t_err			ft_dainit(t_da *da, size_t sz, void *p, size_t len);
void			ft_dainitm(t_da *da, t_m *m);
t_err			ft_daexpand(t_da *da, size_t required);
t_err			ft_daappend(t_da *da, void *elems, size_t count);
void			*ft_danew(t_da *da);
void			ft_daremove(t_da *da, size_t i);
void			*ft_da(t_da *da, size_t i);
void			ft_dafree(t_da *da);

t_err			ft_dsinit(t_ds *ds, char *str);
t_err			ft_dsinitn(t_ds *ds, char *str, size_t len);
void			ft_dsinitm(t_ds *ds, t_m *m);
t_err			ft_dsexpand(t_ds *ds, size_t required);
t_err			ft_dsappend(t_ds *ds, const char *str, size_t n);
t_err			ft_dsappendstr(t_ds *ds, const char *str);
void			ft_dsfree(t_ds *ds);

void			ft_ddinit(t_dd *dd);
void			ft_ddinitda(t_dd *dd, t_da *da);
t_err			ft_ddnew(t_dd *dd, t_d **ppd);
t_err			ft_ddnewinit(t_dd *dd, t_d **ppd, t_byte *mem, size_t len);
t_err			ft_ddappend(t_dd *dd, t_d *d);
void			ft_ddremove(t_dd *dd, size_t i);
void			ft_ddfree(t_dd *dd);

t_err			ft_ddsinit(t_dds *dds, size_t rate);
t_err			ft_ddsappend(t_dds *dds, const char *str, size_t n);
t_err			ft_ddsappendstr(t_dds *dds, const char *str);
t_err			ft_ddsappendraw(t_dds *dds, const char *str, size_t n);
t_err			ft_ddsappendm(t_dds *dds, t_m *m);
t_err			ft_ddsappendvs(t_dds *dds, t_vs *vs);
t_s				ft_dds(t_dds *dds, size_t i);
void			ft_ddsfree(t_dds *dds);
size_t			ft_dds_len(t_dds *dds);
t_err			ft_dds_spread(t_dds *dds, char c, size_t len);

/*
** make vs; dep: -;
*/

t_vs			ft_vs_create(const char *str, size_t len);
t_vs			ft_vs_create_str(const char *str);
t_vs			ft_vs_create_s(t_s *s, size_t offset, size_t len);
t_vs			ft_vs_sub(t_vs *vs, size_t offset, size_t len);
char			ft_vs_inc(t_vs *vs, size_t offset);
char			ft_vs_inc_if(t_vs *vs, char c);
char			ft_vs_inc_if_str(t_vs *vs, char *str);
char			ft_vs_inc_if_word(t_vs *vs, char *str);
int				ft_vs_next(t_vs *vs);
int				ft_vs_next_if(t_vs *vs, char c);
int				ft_vs_next_if_str(t_vs *vs, char *str);
int				ft_vs_next_if_word(t_vs *vs, char *str);
char			ft_vs(t_vs *vs, size_t offset);
void			ft_vs_reset(t_vs *vs);
size_t			ft_vs_strtou(t_vs *vs, t_uint *out, int base, const char *sym);
size_t			ft_vs_strtol(t_vs *vs, int *out, int base, const char *sym);
size_t			ft_vs_strtod(t_vs *vs, double *out);
size_t			ft_vs_read_uint(t_vs *vs, t_uint *out);
size_t			ft_vs_read_int(t_vs *vs, int *out);
size_t			ft_vs_read_int_unsign(t_vs *vs, int *out);
size_t			ft_vs_read_double(t_vs *vs, double *out);
size_t			ft_vs_read_float(t_vs *vs, float *out);
void			ft_vs_skip_ws(t_vs *vs);
void			ft_vs_skip_word(t_vs *vs);
int				ft_vs_str(t_vs *vs, const char *str);
int				ft_vs_word_len(t_vs *vs);
int				ft_vs_word(t_vs *vs, const char *str);

# define FT_VS_SYMX "0123456789abcdef"
# define FT_VS_SYMBIGX "0123456789ABCDEF"

/*
** make b; dep: malloc, free;
*/
int				ft_blen(void *ptr);
int				ft_bcap(void *ptr);
int				ft_bexpand(void *pptr, int required);
int				ft_bappend(void *pptr, void *elem, int sz);
void			*ft_bnew(void *pptr, int sz);
void			ft_bfree(void *pptr);
t_m				ft_b_to_m(void *ptr, int sz);

# define FT_BLEN(ptr) ((int)(ft_blen(ptr) / sizeof(*(ptr))))
# define FT_BCAP(ptr) ((int)(ft_bcap(ptr) / sizeof(*(ptr))))
# define FT_BEXPAND(p, r) ft_bexpand((void *)&(p), (r) * sizeof(*(p)))
# define FT_BAPPEND(p, e) ft_bappend((void *)&(p), e, sizeof(*(p)))
# define FT_BNEW(ptr) ft_bnew((void *)&(ptr), sizeof(*(ptr)))
# define FT_BFREE(ptr) ft_bfree((void *)&(ptr))
# define FT_B_TO_M(ptr) ft_b_to_m(ptr, sizeof(*(ptr)))

/*
** make vmath; dep: -
*/

# define FT_E         2.71828182845904523536028747135266250
# define FT_LOG2E     1.44269504088896340735992468100189214
# define FT_LOG10E    0.434294481903251827651128918916605082
# define FT_LN2       0.693147180559945309417232121458176568
# define FT_LN10      2.30258509299404568401799145468436421
# define FT_PI        3.14159265358979323846264338327950288
# define FT_PI_2      1.57079632679489661923132169163975144
# define FT_PI_4      0.785398163397448309615660845819875721
# define FT_1_PI      0.318309886183790671537767526745028724
# define FT_2_PI      0.636619772367581343075535053490057448
# define FT_2_SQRTPI  1.12837916709551257389615890312154517
# define FT_SQRT2     1.41421356237309504880168872420969808
# define FT_SQRT1_2   0.707106781186547524400844362104849039

# define FT_EF        ((float)FT_E)
# define FT_LOG2EF    ((float)FT_LOG2E)
# define FT_LOG10EF   ((float)FT_LOG10E)
# define FT_LN2F      ((float)FT_LN2)
# define FT_LN10F     ((float)FT_LN10)
# define FT_PIF       ((float)FT_PI)
# define FT_PI_2F     ((float)FT_PI_2)
# define FT_PI_4F     ((float)FT_PI_4)
# define FT_1_PIF     ((float)FT_1_PI)
# define FT_2_PIF     ((float)FT_2_PI)
# define FT_2_SQRTPIF ((float)FT_2_SQRTPI)
# define FT_SQRT2F    ((float)FT_SQRT2)
# define FT_SQRT1_2F  ((float)FT_SQRT1_2)

# define FT_EPS 0.000000001
# define FT_EPSF 0.0000001f

# define FT_RAD(DEG) ((DEG) * (FT_PI / 180.f))
# define FT_DEG(RAD) ((RAD) * (FT_1_PI * 180.f))

void			ft_make_v3(float x, float y, float z, t_v3 out);
void			ft_make_v4(float x, float y, float z, t_v4 out);
void			ft_make_m3(t_v3 c0, t_v3 c1, t_v3 c2, t_m3 out);
void			ft_make_m4(t_v4 c0, t_v4 c1, t_v4 c2, t_m4 out);

void			ft_make_m4_from_m3(t_m3 m, t_m4 out);
void			ft_make_m3_from_m4(t_m4 m, t_m3 out);

void			ft_identity_m3(t_m3 m);
void			ft_identity_m4(t_m4 m);
void			ft_up_vector(t_v3 v);

void			ft_copy_v3(t_v3 l, t_v3 out);
void			ft_copy_v4(t_v4 l, t_v4 out);
void			ft_copy_m3(t_m3 l, t_m3 out);
void			ft_copy_m4(t_m4 l, t_m4 out);

void			ft_mul_v3(t_v3 l, t_v3 r, t_v3 out);
void			ft_div_v3(t_v3 l, t_v3 r, t_v3 out);
void			ft_add_v3(t_v3 l, t_v3 r, t_v3 out);
void			ft_sub_v3(t_v3 l, t_v3 r, t_v3 out);

void			ft_mulvs_v3(t_v3 l, float r, t_v3 out);
void			ft_divvs_v3(t_v3 l, float r, t_v3 out);
void			ft_addvs_v3(t_v3 l, float r, t_v3 out);
void			ft_subvs_v3(t_v3 l, float r, t_v3 out);
void			ft_subsv_v3(float l, t_v3 r, t_v3 out);

float			ft_dot_v3(t_v3 l, t_v3 r);
void			ft_cross_v3_to(t_v3 l, t_v3 r, t_v3 out);
void			ft_lerp_v3(t_v3 l, t_v3 r, float t, t_v3 out);
float			ft_length_v3(t_v3 l);
void			ft_normalize_v3(t_v3 l);

void			ft_mul_v4(t_v4 l, t_v4 r, t_v4 out);
void			ft_div_v4(t_v4 l, t_v4 r, t_v4 out);
void			ft_add_v4(t_v4 l, t_v4 r, t_v4 out);
void			ft_sub_v4(t_v4 l, t_v4 r, t_v4 out);

void			ft_mulvs_v4(t_v4 l, float r, t_v4 out);
void			ft_divvs_v4(t_v4 l, float r, t_v4 out);
void			ft_addvs_v4(t_v4 l, float r, t_v4 out);
void			ft_subvs_v4(t_v4 l, float r, t_v4 out);
void			ft_subsv_v4(float l, t_v4 r, t_v4 out);

float			ft_dot_v4(t_v4 l, t_v4 r);
void			ft_lerp_v4(t_v4 l, t_v4 r, float t, t_v4 out);
float			ft_length_v4(t_v4 l);
void			ft_normalize_v4(t_v4 l);

void			ft_mul_add_v3(t_v3 l, t_v3 r, t_v3 add, t_v3 out);
void			ft_mulvs_add_v3(t_v3 l, float r, t_v3 add, t_v3 out);
void			ft_mul_add_v4(t_v4 l, t_v4 r, t_v4 add, t_v4 out);
void			ft_mulvs_add_v4(t_v4 l, float r, t_v4 add, t_v4 out);

void			ft_mul_m3_to(t_m3 l, t_m3 r, t_m3 out);
void			ft_mul_vm3_to(t_m3 l, t_v3 r, t_v3 out);
void			ft_mul_m3(t_m3 l, t_m3 r, t_m3 out);
void			ft_mul_vm3(t_m3 l, t_v3 r, t_v3 out);

void			ft_mul_m4_to(t_m4 l, t_m4 r, t_m4 out);
void			ft_mul_m4rot_to(t_m4 l, t_m3 r, t_m4 out);
void			ft_mul_vm4_to(t_m4 l, t_v4 r, t_v4 out);
float			ft_mul_v3m4(t_m4 l, t_v3 r, float f3, t_v3 out);
void			ft_persp_mul_v3m4(t_m4 l, t_v3 r, float f3, t_v3 out);

void			ft_transpose_m3(t_m3 l);
void			ft_transpose_m3_to(t_m3 l, t_m3 out);
void			ft_transpose_m4(t_m4 m);
void			ft_transpose_m4_to(t_m4 l, t_m4 out);

void			ft_translate_m4(t_m4 m, t_v3 off);
void			ft_scale_m4(t_m4 m, float s);

void			ft_inv_m4_to(t_m4 l, t_m4 out);
void			ft_inv_m4(t_m4 mat);

/*
** make vmath_ext; dep: vmath, math.h (cosf,sinf,sqrtf)
*/

float			ft_ext_length_v3(t_v3 l);
void			ft_ext_normalize_v3(t_v3 l);
float			ft_ext_length_v4(t_v4 l);
void			ft_ext_normalize_v4(t_v4 l);

void			ft_make_m3rot_x(float angle, t_m3 out);
void			ft_make_m3rot_y(float angle, t_m3 out);
void			ft_make_m3rot_z(float angle, t_m3 out);
void			ft_make_axis_dir(t_v3 dir, t_v3 xout, t_v3 yout, t_v3 zout);
void			ft_make_m3rot_dir(t_v3 dir, t_m3 out);

void			ft_perspective(float aspect, float far, float fov, t_m4 out);
void			ft_lookat(t_v3 pos, t_v3 dir, t_m4 out);

/*
** make vmath_quat; dep: vmath_ext, math.h
*/

void			ft_identity_quat(t_quat q);
void			ft_make_quat_axis(t_v3 axis, float angle, t_quat out);
void			ft_make_quat_dir(t_v3 dir, t_v3 forward, t_v3 up, t_quat out);
void			ft_normalize_quat_to(t_quat l, t_quat out);
void			ft_normalize_quat(t_quat q);

void			ft_conjugate_quat(t_quat q, t_quat out);
void			ft_inverse_quat(t_quat q, t_quat out);
float			ft_angle_quat(t_quat q);
void			ft_axis_quat(t_quat q, t_v3 out);
void			ft_mul_quat(t_v4 p, t_quat q, t_v4 out);

float			ft_real_quat(t_quat q);
void			ft_imag_quat(t_quat q, t_v3 out);
void			ft_imag_normalized_quat(t_quat q, t_v3 out);
float			ft_imag_norm_quat(t_quat q);

void			ft_quat_to_m4(t_quat q, t_m4 out);
void			ft_quat_to_m4_transposed(t_quat q, t_m4 out);
void			ft_quat_to_m3(t_quat q, t_m4 out);
void			ft_quat_to_m3_transposed(t_quat q, t_m4 out);

void			ft_lerp_quat(t_quat l, t_quat r, float t, t_quat out);
void			ft_slerp_quat(t_quat l, t_quat r, float t, t_quat out);
void			ft_lookat_quat(t_v3 pos, t_quat q, t_m4 out);

void			ft_rotate_qv3(t_v3 p, t_quat q, t_v3 out);
void			ft_rotate_qm4(t_m4 m, t_quat q, t_m4 out);
void			ft_rotate_qm4_at(t_m4 m, t_v3 pivot, t_quat q, t_m4 out);

void			ft_quat_to_euler(t_quat q, t_v3 out);
void			ft_euler_to_quat(t_v3 euler, t_quat out);

/*
** make intersection; dep: vmath, math.h
*/

int				ft_triangle_ray_test(t_v3 tr[3], t_ray *r);
int				ft_sphere_ray_test(t_v3 pos, float radius, t_ray *r);
int				ft_plane_ray_test(t_v3 pos, t_v3 normal, t_ray *r);
int				ft_square_ray_test(t_v3 pos[4], t_v3 normal, t_ray *r);
int				ft_cylinder_ray_test(t_v3 p, t_v3 nor, float rhh[2], t_ray *r);

/*
** inline;
*/
# define FT_MIN(l, r) ((l) < (r) ? (l) : (r))
# define FT_MAX(l, r) ((l) > (r) ? (l) : (r))
# define FT_CLAMP(v, l, r) FT_MIN(r, FT_MAX(v, l))
# define FT_USUB(l, r) ((l) <= (r) ? 0 : (l) - (r))
# define FT_ABS(v) ((v) < 0 ? -(v) : (v))
# define FT_SIGN(v) ((v) < 0 ? -1 : 1)

/*
** ctype
*/
extern const unsigned char	g_ctype_char_info[256];

# define IS_ALNUM(x) (g_ctype_char_info[(unsigned char)(x)] & 1)
# define IS_ALPHA(x) (g_ctype_char_info[(unsigned char)(x)] & 2)
# define IS_DIGIT(x) (g_ctype_char_info[(unsigned char)(x)] & 4)
# define IS_LOWER(x) (g_ctype_char_info[(unsigned char)(x)] & 8)
# define IS_PRINT(x) (g_ctype_char_info[(unsigned char)(x)] & 16)
# define IS_SPACE(x) (g_ctype_char_info[(unsigned char)(x)] & 32)
# define IS_UPPER(x) (g_ctype_char_info[(unsigned char)(x)] & 64)
# define IS_XDIGIT(x) (g_ctype_char_info[(unsigned char)(x)] & 128)

# define IS_ASCII(x) ((char)(unsigned char)(x) >= 0)

#endif
