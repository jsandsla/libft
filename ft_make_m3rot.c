/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_m3rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:42:19 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 20:11:56 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_make_m3rot_x(t_m3 m, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(m);
	m[1][1] = c;
	m[2][1] = -s;
	m[1][2] = s;
	m[2][2] = c;
}

void	ft_make_m3rot_y(t_m3 m, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(m);
	m[0][0] = c;
	m[0][2] = -s;
	m[2][0] = s;
	m[2][2] = c;
}

void	ft_make_m3rot_z(t_m3 m, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(m);
	m[0][0] = c;
	m[1][0] = -s;
	m[0][1] = s;
	m[1][1] = c;
}

void	ft_make_m3rot_dir(t_m3 m, t_v3 dir)
{
	t_v3	up;
	t_v3	right;
	t_v3	dir_up;

	ft_up_vector(up);
	ft_cross_v3_to(up, dir, right);
	ft_normalize_v3(right);
	ft_cross_v3_to(dir, right, dir_up);
	ft_normalize_v3(dir_up);
	m[0][0] = right[0];
	m[1][0] = right[1];
	m[2][0] = right[2];
	m[0][1] = dir_up[0];
	m[1][1] = dir_up[1];
	m[2][1] = dir_up[2];
	m[0][2] = dir[0];
	m[1][2] = dir[1];
	m[2][2] = dir[2];
}
