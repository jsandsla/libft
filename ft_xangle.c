/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:27:12 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:22:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void			ft_make_xangle_dir(t_v3 ndir, t_v4 xangle)
{
	t_v3	dir;

	ft_copy_v3(ndir, dir);
	if (ft_dot_v3(dir, dir) < FT_EPSF)
		ft_make_v3(0, 0, 1, dir);
	ft_ext_normalize_v3(dir);
	ft_make_v3(dir[0], 0, dir[2], xangle);
	if (ft_dot_v3(xangle, xangle) < FT_EPSF)
		ft_make_v3(0, 0, 1, xangle);
	xangle[3] = acosf(ft_dot_v3((t_v3){0, 1, 0}, dir));
	xangle[3] = FT_CLAMP(xangle[3], 0, FT_PIF);
}

void			ft_make_xangle_axis(t_v4 xangle, t_v3 x, t_v3 y, t_v3 z)
{
	t_quat	q;

	ft_subsv_v3(0, xangle, z);
	ft_cross_v3_to((t_v3){0, 1, 0}, z, x);
	ft_make_quat_axis(x, xangle[3] - FT_PI_2F, q);
	ft_rotate_qv3(z, q, z);
	ft_cross_v3_to(z, x, y);
	ft_ext_normalize_v3(x);
	ft_ext_normalize_v3(y);
	ft_ext_normalize_v3(z);
}

void			ft_make_dir_xangle(t_v4 xangle, t_v3 dir)
{
	t_quat	q;
	t_v3	x;

	ft_subsv_v3(0, xangle, dir);
	ft_cross_v3_to((t_v3){0, 1, 0}, dir, x);
	ft_make_quat_axis(x, xangle[3] - FT_PI_2F, q);
	ft_rotate_qv3(dir, q, dir);
	ft_subsv_v3(0, dir, dir);
}

void			ft_rotate_xangle(t_v4 xangle, float angle_x, float angle_y)
{
	t_quat	q;

	xangle[3] += angle_x;
	xangle[3] = FT_CLAMP(xangle[3], 0, FT_PIF);
	if (!ft_epsf(angle_y, FT_EPSF))
	{
		ft_make_quat_axis((t_v3){0, 1, 0}, angle_y, q);
		ft_rotate_qv3(xangle, q, xangle);
	}
}

void			ft_lookat_xangle(t_v3 pos, t_v4 xangle, t_m4 out)
{
	t_v3	axis[3];

	ft_make_xangle_axis(xangle, axis[0], axis[1], axis[2]);
	out[0][0] = axis[0][0];
	out[0][1] = axis[1][0];
	out[0][2] = axis[2][0];
	out[0][3] = 0;
	out[1][0] = axis[0][1];
	out[1][1] = axis[1][1];
	out[1][2] = axis[2][1];
	out[1][3] = 0;
	out[2][0] = axis[0][2];
	out[2][1] = axis[1][2];
	out[2][2] = axis[2][2];
	out[2][3] = 0;
	out[3][0] = -ft_dot_v3(pos, axis[0]);
	out[3][1] = -ft_dot_v3(pos, axis[1]);
	out[3][2] = -ft_dot_v3(pos, axis[2]);
	out[3][3] = 1;
}
