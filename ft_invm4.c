/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invm4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:25:34 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 17:17:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define a mat->r0.x
#define b mat->r1.x
#define c mat->r2.x
#define d mat->r3.x

#define e mat->r0.y
#define f mat->r1.y
#define g mat->r2.y
#define h mat->r3.y

#define i mat->r0.z
#define j mat->r1.z
#define k mat->r2.z
#define l mat->r3.z

#define m mat->r0.w
#define n mat->r1.w
#define o mat->r2.w
#define p mat->r3.w

static	void	calc_t1(float t[6], t_m4 *mat)
{
	t[0] = k * p - o * l;
	t[1] = j * p - n * l;
	t[2] = j * o - n * k;
	t[3] = i * p - m * l;
	t[4] = i * o - m * k;
	t[5] = i * n - m * j;
}

static	void	calc_t2(float t[6], t_m4 *mat)
{
	t[0] = g * p - o * h;
	t[1] = f * p - n * h;
	t[2] = f * o - n * g;
	t[3] = e * p - m * h;
	t[4] = e * o - m * g;
	t[5] = e * n - m * f;
}

static	void	calc_t3(float t[6], t_m4 *mat)
{
	t[0] = g * l - k * h;
	t[1] = f * l - j * h;
	t[2] = f * k - j * g;
	t[3] = e * l - i * h;
	t[4] = e * k - i * g;
	t[5] = e * j - i * f;
}

void	ft_inv_m4_to(t_m4 *mat, t_m4 *out)
{
	float	t[6];
	float	det;

	calc_t1(t, mat);
	out->r0.x =  f * t[0] - g * t[1] + h * t[2];
	out->r0.y =-(e * t[0] - g * t[3] + h * t[4]);
	out->r0.z =  e * t[1] - f * t[3] + h * t[5];
	out->r0.w =-(e * t[2] - f * t[4] + g * t[5]);
	out->r1.x =-(b * t[0] - c * t[1] + d * t[2]);
	out->r1.y =  a * t[0] - c * t[3] + d * t[4];
	out->r1.z =-(a * t[1] - b * t[3] + d * t[5]);
	out->r1.w =  a * t[2] - b * t[4] + c * t[5];
	calc_t2(t, mat);
	out->r2.x =  b * t[0] - c * t[1] + d * t[2];
	out->r2.y =-(a * t[0] - c * t[3] + d * t[4]);
	out->r2.z =  a * t[1] - b * t[3] + d * t[5];
	out->r2.w =-(a * t[2] - b * t[4] + c * t[5]);
	calc_t3(t, mat);
	out->r3.x =-(b * t[0] - c * t[1] + d * t[2]);
	out->r3.y =  a * t[0] - c * t[3] + d * t[4];
	out->r3.z =-(a * t[1] - b * t[3] + d * t[5]);
	out->r3.w =  a * t[2] - b * t[4] + c * t[5];
	det = 1 / (a * out->r0.x + b * out->r0.y + c * out->r0.z + d * out->r0.w);
	ft_scale_m4(mat, det);
}

void	ft_inv_m4(t_m4 *mat)
{
	t_m4	ma;

	ft_inv_m4_to(mat, &ma);
	*mat = ma;
}
