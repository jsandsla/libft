/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:13:55 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 18:11:32 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static	void	compute_m(t_m3 m, t_quat q)
{
	float	s;
	float	norm;

	norm = sqrtf(ft_dot_v4(q, q));
	s = norm > 0 ? 2.f / norm : 0;
	m[0][0] = s * q[0] * q[0];
	m[0][1] = s * q[0] * q[1];
	m[0][2] = s * q[0] * q[3];
	m[1][0] = s * q[1] * q[1];
	m[1][1] = s * q[1] * q[2];
	m[1][2] = s * q[1] * q[3];
	m[2][0] = s * q[2] * q[2];
	m[2][1] = s * q[2] * q[0];
	m[2][2] = s * q[2] * q[3];
}

void			ft_quat_to_m4(t_quat q, t_m4 out)
{
	t_m3	m;

	compute_m(m, q);
	out[0][0] = 1.0f - m[1][0] - m[2][0];
	out[1][1] = 1.0f - m[0][0] - m[2][0];
	out[2][2] = 1.0f - m[0][0] - m[1][0];
	out[0][1] = m[0][1] + m[2][2];
	out[1][2] = m[1][1] + m[0][2];
	out[2][0] = m[2][1] + m[1][2];
	out[1][0] = m[0][1] - m[2][2];
	out[2][1] = m[1][1] - m[0][2];
	out[0][2] = m[2][1] - m[1][2];
	out[0][3] = 0.0f;
	out[1][3] = 0.0f;
	out[2][3] = 0.0f;
	out[3][0] = 0.0f;
	out[3][1] = 0.0f;
	out[3][2] = 0.0f;
	out[3][3] = 1.0f;
}

void			ft_quat_to_m4_transposed(t_quat q, t_m4 out)
{
	#if 0
	t_m3	m;

	compute_m(m, q);
	out[0][0] = 1.0f - m[1][0] - m[2][0];
	out[1][1] = 1.0f - m[0][0] - m[2][0];
	out[2][2] = 1.0f - m[0][0] - m[1][0];
	out[1][0] = m[0][1] + m[2][2];
	out[2][1] = m[1][1] + m[0][2];
	out[0][2] = m[2][1] + m[1][2];
	out[0][1] = m[0][1] - m[2][2];
	out[1][2] = m[1][1] - m[0][2];
	out[2][0] = m[2][1] - m[1][2];
	out[0][3] = 0.0f;
	out[1][3] = 0.0f;
	out[2][3] = 0.0f;
	out[3][0] = 0.0f;
	out[3][1] = 0.0f;
	out[3][2] = 0.0f;
	out[3][3] = 1.0f;
	#else
float w, x, y, z, xx, yy, zz, xy, yz, xz, wx, wy, wz, norm, s;\
	norm = sqrtf(ft_dot_v4(q,q));\
	s    = norm > 0.0f ? 2.0f / norm : 0.0f;\
	x = (q)[0];\
	y = (q)[1];\
	z = (q)[2];\
	w = (q)[3];\
	xx = s * x * x;   xy = s * x * y;   wx = s * w * x;\
	yy = s * y * y;   yz = s * y * z;   wy = s * w * y;\
	zz = s * z * z;   xz = s * x * z;   wz = s * w * z;\
	(out)[0][0] = 1.0f - yy - zz;\
	(out)[1][1] = 1.0f - xx - zz;\
	(out)[2][2] = 1.0f - xx - yy;\
	(out)[1][0] = xy + wz;\
	(out)[2][1] = yz + wx;\
	(out)[0][2] = xz + wy;\
	(out)[0][1] = xy - wz;\
	(out)[1][2] = yz - wx;\
	(out)[2][0] = xz - wy;\
	(out)[0][3] = 0.0f;\
	(out)[1][3] = 0.0f;\
	(out)[2][3] = 0.0f;\
	(out)[3][0] = 0.0f;\
	(out)[3][1] = 0.0f;\
	(out)[3][2] = 0.0f;\
	(out)[3][3] = 1.0f;
	#endif
}

void			ft_quat_to_m3(t_quat q, t_m4 out)
{
	t_m3	m;

	compute_m(m, q);
	out[0][0] = 1.0f - m[1][0] - m[2][0];
	out[1][1] = 1.0f - m[0][0] - m[2][0];
	out[2][2] = 1.0f - m[0][0] - m[1][0];
	out[0][1] = m[0][1] + m[2][2];
	out[1][2] = m[1][1] + m[0][2];
	out[2][0] = m[2][1] + m[1][2];
	out[1][0] = m[0][1] - m[2][2];
	out[2][1] = m[1][1] - m[0][2];
	out[0][2] = m[2][1] - m[1][2];
}

void			ft_quat_to_m3_transposed(t_quat q, t_m4 out)
{
	t_m3	m;

	compute_m(m, q);
	out[0][0] = 1.0f - m[1][0] - m[2][0];
	out[1][1] = 1.0f - m[0][0] - m[2][0];
	out[2][2] = 1.0f - m[0][0] - m[1][0];
	out[1][0] = m[0][1] + m[2][2];
	out[2][1] = m[1][1] + m[0][2];
	out[0][2] = m[2][1] + m[1][2];
	out[0][1] = m[0][1] - m[2][2];
	out[1][2] = m[1][1] - m[0][2];
	out[2][0] = m[2][1] - m[1][2];
}
