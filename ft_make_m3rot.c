/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_m3rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:42:19 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 13:44:20 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_make_m3rot_x(float angle, t_m3 out)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(out);
	out[1][1] = c;
	out[2][1] = -s;
	out[1][2] = s;
	out[2][2] = c;
}

void	ft_make_m3rot_y(float angle, t_m3 out)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(out);
	out[0][0] = c;
	out[0][2] = -s;
	out[2][0] = s;
	out[2][2] = c;
}

void	ft_make_m3rot_z(float angle, t_m3 out)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(out);
	out[0][0] = c;
	out[1][0] = -s;
	out[0][1] = s;
	out[1][1] = c;
}

void	ft_make_axis_dir(t_v3 dir, t_v3 xout, t_v3 yout, t_v3 zout)
{
	t_v3	vec;

	ft_make_v3(0, 1, 0, vec);
	if (ft_fabs(ft_dot_v3(dir, vec)) - 1 > 0.001f)
	{
		ft_copy_v3(dir, zout);
		ft_ext_normalize_v3(zout);
		ft_cross_v3_to(vec, zout, xout);
		ft_cross_v3_to(zout, xout, yout);
	}
	else
	{
		ft_make_v3(1, 0, 0, vec);
		ft_copy_v3(dir, zout);
		ft_cross_v3_to(zout, vec, yout);
		ft_cross_v3_to(yout, zout, xout);
	}
}

void	ft_make_m3rot_dir(t_v3 dir, t_m3 out)
{
	t_v3	up;
	t_v3	forward;
	t_v3	right;

	ft_make_axis_dir(dir, right, up, forward);
	out[0][0] = right[0];
	out[0][1] = right[1];
	out[0][2] = right[2];
	out[1][0] = up[0];
	out[1][1] = up[1];
	out[1][2] = up[2];
	out[2][0] = forward[0];
	out[2][1] = forward[1];
	out[2][2] = forward[2];
}
