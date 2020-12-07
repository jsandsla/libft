/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:34:39 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:29:35 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static	int		calc_hits(t_ray *r, float t[2], float rhh[2], float z[2])
{
	float	b;
	float	a;
	float	d;
	float	subsq;

	b = 2 * r->ori[0] * r->dir[0] + 2 * r->ori[1] * r->dir[1];
	a = r->dir[0] * r->dir[0] + r->dir[1] * r->dir[1];
	subsq = b * b - 4 * a * (r->ori[0] * r->ori[0] + r->ori[1] * r->ori[1] -
			(rhh[0] * rhh[0]));
	if (subsq < 0 || ft_epsf(a, FT_EPSF))
		return (0);
	d = sqrtf(subsq);
	t[0] = (-b - d) / (2 * a);
	t[1] = (-b + d) / (2 * a);
	if (t[0] < 0 && t[1] < 0)
		return (0);
	z[0] = r->ori[2] + t[0] * r->dir[2];
	z[1] = r->ori[2] + t[1] * r->dir[2];
	return (1);
}

static	int		calc_normal(t_m4 rot, t_ray *r, t_ray *rr)
{
	t_v3	onormal;
	t_m3	invrot;

	r->hit = rr->hit;
	ft_mulvs_add_v3(rr->dir, rr->hit, rr->ori, onormal);
	onormal[2] = 0;
	ft_ext_normalize_v3(onormal);
	if (ft_dot_v3(onormal, rr->dir) > 0)
		ft_subsv_v3(0, onormal, onormal);
	ft_make_m3_from_m4(rot, invrot);
	ft_transpose_m3(invrot);
	ft_mul_vm3(invrot, onormal, r->hitnormal);
	return (1);
}

int				ft_cylinder_ray_test(t_v3 pos, t_v3 normal, float rhh[2],
	t_ray *r)
{
	t_m4	rot;
	t_ray	rr;
	float	t[2];
	float	z[2];
	t_v4	xangle;

	ft_make_xangle_dir(normal, xangle);
	ft_lookat_xangle(pos, xangle, rot);
	ft_mul_v3m4(rot, r->ori, 1, rr.ori);
	ft_mul_v3m4(rot, r->dir, 0, rr.dir);
	ft_ext_normalize_v3(rr.dir);
	if (!calc_hits(&rr, t, rhh, z))
		return (0);
	if (!(z[0] > -rhh[1] && z[0] < rhh[1]) || t[0] < 0)
		t[0] = INFINITY;
	if (!(z[1] > -rhh[1] && z[1] < rhh[1]) || t[1] < 0)
		t[1] = INFINITY;
	if (t[0] == INFINITY && t[1] == INFINITY)
		return (0);
	rr.hit = t[0];
	if (t[1] < t[0])
		rr.hit = t[1];
	if (r->hit < rr.hit)
		return (0);
	return (calc_normal(rot, r, &rr));
}
