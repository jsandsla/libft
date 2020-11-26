/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_m3rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:42:19 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 17:02:08 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_make_m3rot_x(t_m3 *m, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(m);
	m->r1.y = c;
	m->r1.z = -s;
	m->r2.y = s;
	m->r2.z = c;
}

void	ft_make_m3rot_y(t_m3 *m, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(m);
	m->r0.x = c;
	m->r2.x = -s;
	m->r0.z = s;
	m->r2.z = c;
}

void	ft_make_m3rot_z(t_m3 *m, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(m);
	m->r0.x = c;
	m->r0.y = -s;
	m->r1.x = s;
	m->r1.y = c;
}

void	ft_make_m3rot_dir(t_m3 *m, t_v3 *dir)
{
	t_v3	up;
	t_v3	right;
	t_v3	dir_up;

	up = FT_UP_VECTOR;
	ft_cross_v3_to(&up, dir, &right);
	ft_normalize_v3(&right);
	ft_cross_v3_to(dir, &right, &dir_up);
	ft_normalize_v3(&dir_up);
	m->r0 = right;
	m->r1 = dir_up;
	m->r2 = *dir;
}
