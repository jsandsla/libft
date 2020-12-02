/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invm4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:25:34 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 18:00:30 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#if 0
#define a mat[0][0]
#define b mat[0][1]
#define c mat[0][2]
#define d mat[0][3]

#define e mat[1][0]
#define f mat[1][1]
#define g mat[1][2]
#define h mat[1][3]

#define i mat[2][0]
#define j mat[2][1]
#define k mat[2][2]
#define l mat[2][3]

#define m mat[3][0]
#define n mat[3][1]
#define o mat[3][2]
#define p mat[3][3]

static	void	calc_t1(float t[6], t_m4 mat)
{
	t[0] = k * p - o * l;
	t[1] = j * p - n * l;
	t[2] = j * o - n * k;
	t[3] = i * p - m * l;
	t[4] = i * o - m * k;
	t[5] = i * n - m * j;
}

static	void	calc_t2(float t[6], t_m4 mat)
{
	t[0] = g * p - o * h;
	t[1] = f * p - n * h;
	t[2] = f * o - n * g;
	t[3] = e * p - m * h;
	t[4] = e * o - m * g;
	t[5] = e * n - m * f;
}

static	void	calc_t3(float t[6], t_m4 mat)
{
	t[0] = g * l - k * h;
	t[1] = f * l - j * h;
	t[2] = f * k - j * g;
	t[3] = e * l - i * h;
	t[4] = e * k - i * g;
	t[5] = e * j - i * f;
}
#endif
void	ft_inv_m4_to(t_m4 mat, t_m4 out)
{
	#if 0
	float	t[6];
	float	det;

	calc_t1(t, mat);
	out[0][0] =  f * t[0] - g * t[1] + h * t[2];
	out[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
	out[2][0] =  e * t[1] - f * t[3] + h * t[5];
	out[3][0] =-(e * t[2] - f * t[4] + g * t[5]);
	out[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
	out[1][1] =  a * t[0] - c * t[3] + d * t[4];
	out[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
	out[3][1] =  a * t[2] - b * t[4] + c * t[5];
	calc_t2(t, mat);
	out[0][2] =  b * t[0] - c * t[1] + d * t[2];
	out[1][2] =-(a * t[0] - c * t[3] + d * t[4]);
	out[2][2] =  a * t[1] - b * t[3] + d * t[5];
	out[3][2] =-(a * t[2] - b * t[4] + c * t[5]);
	calc_t3(t, mat);
	out[0][3] =-(b * t[0] - c * t[1] + d * t[2]);
	out[1][3] =  a * t[0] - c * t[3] + d * t[4];
	out[2][3] =-(a * t[1] - b * t[3] + d * t[5]);
	out[3][3] =  a * t[2] - b * t[4] + c * t[5];
	det = 1 / (a * out[0][0] + b * out[1][0] + c * out[2][0] + d * out[3][0]);
	ft_scale_m4(mat, det);
	#else
float t[6]; float det; float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;\
	a = mat[0][0]; b = mat[0][1]; c = mat[0][2]; d = mat[0][3];\
	e = mat[1][0]; f = mat[1][1]; g = mat[1][2]; h = mat[1][3];\
	i = mat[2][0]; j = mat[2][1]; k = mat[2][2]; l = mat[2][3];\
	m = mat[3][0]; n = mat[3][1]; o = mat[3][2]; p = mat[3][3];\
	t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;\
	t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;\
	(out)[0][0] =  f * t[0] - g * t[1] + h * t[2];\
	(out)[1][0] =-(e * t[0] - g * t[3] + h * t[4]);\
	(out)[2][0] =  e * t[1] - f * t[3] + h * t[5];\
	(out)[3][0] =-(e * t[2] - f * t[4] + g * t[5]);\
	(out)[0][1] =-(b * t[0] - c * t[1] + d * t[2]);\
	(out)[1][1] =  a * t[0] - c * t[3] + d * t[4];\
	(out)[2][1] =-(a * t[1] - b * t[3] + d * t[5]);\
	(out)[3][1] =  a * t[2] - b * t[4] + c * t[5];\
	t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;\
	t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;\
	(out)[0][2] =  b * t[0] - c * t[1] + d * t[2];\
	(out)[1][2] =-(a * t[0] - c * t[3] + d * t[4]);\
	(out)[2][2] =  a * t[1] - b * t[3] + d * t[5];\
	(out)[3][2] =-(a * t[2] - b * t[4] + c * t[5]);\
	t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;\
	t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;\
	(out)[0][3] =-(b * t[0] - c * t[1] + d * t[2]);\
	(out)[1][3] =  a * t[0] - c * t[3] + d * t[4];\
	(out)[2][3] =-(a * t[1] - b * t[3] + d * t[5]);\
	(out)[3][3] =  a * t[2] - b * t[4] + c * t[5];\
	det = 1.0f / (a * out[0][0] + b * out[1][0] + c * out[2][0] + d * out[3][0]);\
	ft_scale_m4(out, det);
	#endif
}

void	ft_inv_m4(t_m4 mat)
{
	t_m4	ma;

	ft_inv_m4_to(mat, ma);
	ft_copy_m4(ma, mat);
}
