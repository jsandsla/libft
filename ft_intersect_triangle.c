/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:21:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/03 16:01:43 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		prepare_ray(t_v3 edge[2], t_ray *r, float a, float hit)
{
	r->hit = hit;
	if (a < 0)
		ft_cross_v3_to(edge[1], edge[0], r->hitnormal);
	else
		ft_cross_v3_to(edge[0], edge[1], r->hitnormal);
	return (1);
}

int				ft_triangle_ray_test(t_v3 tr[3], t_ray *r)
{
	t_v3	h;
	t_v3	edge[2];
	t_v3	q[2];
	float	a[3];
	float	hit;

	ft_sub_v3(tr[1], tr[0], edge[0]);
	ft_sub_v3(tr[2], tr[0], edge[1]);
	ft_cross_v3_to(r->dir, edge[1], h);
	a[0] = ft_dot_v3(edge[0], h);
	if ((a[0] < 0 ? -a[0] : a[0]) < FT_EPSF)
		return (0);
	a[0] = 1 / a[0];
	ft_sub_v3(r->ori, tr[0], q[1]);
	a[1] = a[0] * ft_dot_v3(q[1], h);
	if (a[1] < 0 || a[1] > 1)
		return (0);
	ft_cross_v3_to(q[1], edge[0], q[0]);
	a[2] = a[0] * ft_dot_v3(r->dir, q[0]);
	if (a[2] < 0 || a[2] + a[1] > 1)
		return (0);
	hit = a[0] * ft_dot_v3(edge[1], q[0]);
	if (hit < 0 || r->hit < hit)
		return (0);
	return (prepare_ray(edge, r, a[0], hit));
}
