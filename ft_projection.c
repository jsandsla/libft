/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:37:03 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/02 17:50:53 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_perspective(float aspect, float far, float fov, t_m4 out)
{
	float	near;
	float	b;
	float	r;
	float	p;

	near = 0.1f;
	p = near * tanf(FT_RAD(fov) * 0.5f);
	if (aspect > 0)
	{
		b = p;
		r = p * aspect;
	}
	else
	{
		aspect = 1 / aspect;
		b = p * aspect;
		r = p;
	}
	ft_bzero(out, sizeof(t_m4));
	out[0][0] = near / r;
	out[1][1] = near / b;
	out[2][3] = -1;
	out[2][2] = (far + near) / (near - far);
	out[3][2] = 2 * far * near / (near - far);
}

void			ft_lookat(t_v3 pos, t_v3 dir, t_m4 out)
{
	t_v3	up;
	t_v3	forward;
	t_v3	right;

//	ft_copy_v3(dir, forward);
//	ft_ext_normalize_v3(forward);
	ft_make_axis_dir(dir, right, up, forward);
	out[0][0] = right[0];
	out[0][1] = up[0];
	out[0][2] = forward[0];
	out[0][3] = 0;
	out[1][0] = right[1];
	out[1][1] = up[1];
	out[1][2] = forward[1];
	out[1][3] = 0;
	out[2][0] = right[2];
	out[2][1] = up[2];
	out[2][2] = forward[2];
	out[2][3] = 0;
	out[3][0] = -ft_dot_v3(pos, right);
	out[3][1] = -ft_dot_v3(pos, up);
	out[3][2] = -ft_dot_v3(pos, forward);
	out[3][3] = 1;
}
