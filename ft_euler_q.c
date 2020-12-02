/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_euler_q.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:02:15 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 20:09:59 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void			ft_quat_to_euler(t_quat q, t_v3 out)
{
	float	sin_cos;
	float	cos_cos;
	float	sinp;

	sin_cos = 2 * q[3] * q[0] + q[1] * q[2];
	cos_cos = 1 - 2 * (q[0] * q[0] + q[1] * q[1]);
	out[0] = atan2f(sin_cos, cos_cos);
	sinp = 2 * (q[3] * q[1] - q[2] * q[0]);
	if (ft_fabsf(sinp) >= 1)
		out[1] = ft_copysignf(M_PI_2, sinp);
	else
		out[1] = asinf(sinp);
	sin_cos = 2 * (q[3] * q[2] + q[0] * q[1]);
	cos_cos = 1 - 2 * (q[1] * q[1] + q[2] * q[2]);
	out[2] = atan2f(sin_cos, cos_cos);
}

void			ft_euler_to_quat(t_v3 euler, t_quat out)
{
	t_v3	s;
	t_v3	c;

	s[0] = sinf(euler[2] * 0.5f);
	s[1] = sinf(euler[1] * 0.5f);
	s[2] = sinf(euler[0] * 0.5f);
	c[0] = cosf(euler[2] * 0.5f);
	c[1] = cosf(euler[1] * 0.5f);
	c[2] = cosf(euler[0] * 0.5f);
	out[3] = c[2] * c[1] * c[0] + s[2] * s[1] * s[0];
	out[0] = s[2] * c[1] * c[0] - c[2] * s[1] * s[0];
	out[1] = c[2] * s[1] * c[0] + s[2] * c[1] * s[0];
	out[2] = c[2] * c[1] * s[0] - s[2] * s[1] * c[0];
}
