/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:44:40 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:29:15 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void			ft_identity_quat(t_quat q)
{
	q[0] = 0;
	q[1] = 0;
	q[2] = 0;
	q[3] = 1;
}

void			ft_make_quat_axis(t_v3 axis, float angle, t_quat out)
{
	t_v3	k;
	float	a;
	float	c;
	float	s;

	a = angle * 0.5f;
	c = cosf(a);
	s = sinf(a);
	ft_copy_v3(axis, k);
	ft_ext_normalize_v3(k);
	out[0] = s * k[0];
	out[1] = s * k[1];
	out[2] = s * k[2];
	out[3] = c;
}

void			ft_make_quat_dir(t_v3 dir, t_quat out)
{
	t_v3	axis;
	float	dot;
	float	angle;

	dot = ft_dot_v3(dir, (t_v3){0, 0, 1});
	if (ft_fabs(dot + 1.f) < FT_EPSF)
		ft_make_quat_axis((t_v3){0, 1, 0}, FT_PIF, out);
	else
	{
		if (ft_fabs(dot - 1.f) < FT_EPSF)
			ft_identity_quat(out);
		else
		{
			angle = acosf(dot);
			ft_cross_v3_to((t_v3){0, 0, 1}, dir, axis);
			ft_make_quat_axis(axis, angle, out);
		}
	}
}

void			ft_normalize_quat_to(t_quat l, t_quat out)
{
	float	dot;

	dot = ft_dot_v4(l, l);
	if (dot <= 0)
		ft_identity_quat(out);
	else
	{
		dot = 1 / sqrtf(dot);
		out[0] = l[0] * dot;
		out[1] = l[1] * dot;
		out[2] = l[2] * dot;
		out[3] = l[3] * dot;
	}
}

void			ft_normalize_quat(t_quat q)
{
	ft_normalize_quat_to(q, q);
}
