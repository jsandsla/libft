/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usequat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:59:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 15:30:06 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void			ft_conjugate_quat(t_quat q, t_quat out)
{
	out[0] = -q[0];
	out[1] = -q[1];
	out[2] = -q[2];
	out[3] = q[3];
}

void			ft_inverse_quat(t_quat q, t_quat out)
{
	t_quat	conj;
	float	scl;

	ft_conjugate_quat(q, conj);
	scl = ft_dot_v4(q, q);
	if (ft_epsilon(scl, FT_EPSF))
	{
		out[0] = conj[0] * INFINITY;
		out[1] = conj[1] * INFINITY;
		out[2] = conj[2] * INFINITY;
		out[3] = conj[3] * INFINITY;
	}
	else
	{
		scl = 1 / scl;
		out[0] = conj[0] * scl;
		out[1] = conj[1] * scl;
		out[2] = conj[2] * scl;
		out[3] = conj[3] * scl;
	}
}

float			ft_angle_quat(t_quat q)
{
	float	norm;
	float	angle;

	norm = ft_imag_norm_quat(q);
	angle = 2.f * atan2(norm, q[3]);
	return (angle);
}

void			ft_axis_quat(t_quat q, t_v3 out)
{
	ft_imag_normalized_quat(q, out);
}

void			ft_mul_quat(t_v4 p, t_quat q, t_v4 out)
{
	t_quat	t;

	t[0] = p[3] * q[0] + p[0] * q[3] + p[1] * q[2] - p[2] * q[1];
	t[1] = p[3] * q[1] - p[0] * q[2] + p[1] * q[3] + p[2] * q[0];
	t[2] = p[3] * q[2] + p[0] * q[1] - p[1] * q[0] + p[2] * q[3];
	t[3] = p[3] * q[3] - p[0] * q[0] - p[1] * q[1] - p[2] * q[2];
	ft_copy_v4(t, out);
}
