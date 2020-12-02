/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:21:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/02 17:02:27 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_triangle_ray_test(t_v3 tr[3], t_ray *r)
{
	t_v3	h;
	t_v3	edge1;
	t_v3	edge2;
	t_v3	q[2];
	float	a[3];

	ft_sub_v3(tr[1], tr[0], edge1);
	ft_sub_v3(tr[2], tr[0], edge2);
	ft_cross_v3_to(r->dir, edge2, h);
	a[0] = ft_dot_v3(edge1, h);
	if ((a[0] < 0 ? -a[0] : a[0]) < FT_EPSF)
		return (0);
	a[0] = 1 / a[0];
	ft_sub_v3(r->ori, tr[0], q[1]);
	a[1] = a[0] * ft_dot_v3(q[1], h);
	if (a[1] < 0 || a[1] > 1)
		return (0);
	ft_cross_v3_to(q[1], edge1, q[0]);
	a[2] = a[0] * ft_dot_v3(r->dir, q[0]);
	if (a[2] < 0 || a[2] + a[1] > 1)
		return (0);
	r->hit = a[0] * ft_dot_v3(edge2, q[0]);
	if (r->hit > FT_EPSF)
	{
		if (a[0] < 0)
			ft_cross_v3_to(edge2, edge1, r->hitnormal);
		else
			ft_cross_v3_to(edge1, edge2, r->hitnormal);
		return (1);
	}
	return (0);
}
