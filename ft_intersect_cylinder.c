/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:34:39 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/02 18:19:28 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

#include <stdio.h>

int				ft_cylinder_ray_test(t_v3 pos, t_v3 normal, float rhh[2], t_ray *r)
{
	t_m4	rot;
	t_ray	rr;
	float	t[2];
	float	z[2];
	float	b, a, d, subsq;

	ft_lookat(pos, normal, rot);
	ft_mul_v3m4(rot, r->ori, 1, rr.ori);
	ft_mul_v3m4(rot, r->dir, 0, rr.dir);
	ft_ext_normalize_v3(rr.dir);
	b = 2 * rr.ori[0] * rr.dir[0] + 2 * rr.ori[1] * rr.dir[1];
	a = rr.dir[0] * rr.dir[0] + rr.dir[1] * rr.dir[1];
	subsq = b * b - 4 * a * (rr.ori[0] * rr.ori[0] + rr.ori[1] * rr.ori[1] -
			(rhh[0] * rhh[0]));
	if (subsq < 0 || ft_epsf(a, FT_EPSF))
		return (0);
	d = sqrtf(subsq);
	t[0] = (-b - d) / (2 * a);
	t[1] = (-b + d) / (2 * a);
	if (t[0] < 0 && t[1] < 0)
		return (0);
	z[0] = rr.ori[2] + t[0] * rr.dir[2];
	z[1] = rr.ori[2] + t[1] * rr.dir[2];
	if (!(z[0] > -rhh[1] && z[0] < rhh[1]) || t[0] < 0)
		t[0] = INFINITY;
	if (!(z[1] > -rhh[1] && z[1] < rhh[1]) || t[1] < 0)
		t[1] = INFINITY;
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (0);
	r->hit = t[0];
	if (t[1] < t[0])
		r->hit = t[1];
	{
		t_v3	onormal;
		t_m3	invrot;

		ft_mulvs_add_v3(rr.dir, r->hit, rr.ori, onormal);
		onormal[2] = 0;
		ft_ext_normalize_v3(onormal);
		if (ft_dot_v3(onormal, rr.dir) > 0)
			ft_subsv_v3(0, onormal, onormal);
		ft_make_m3_from_m4(rot, invrot);
		ft_transpose_m3(invrot);
		ft_mul_vm3(invrot, onormal, r->hitnormal);
	}
	return (1);
}
