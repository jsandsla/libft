/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:15:32 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:16:05 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static	void	swap_float(float *l, float *r)
{
	float	temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

static	void	calc_normal(t_v3 pos, t_ray *r, float hit, float t[2])
{
	ft_mulvs_add_v3(r->dir, hit, r->ori, r->hitnormal);
	if (t[0] < 0 || t[1] < 0)
		ft_sub_v3(pos, r->hitnormal, r->hitnormal);
	else
		ft_sub_v3(r->hitnormal, pos, r->hitnormal);
}

int				ft_sphere_ray_test(t_v3 pos, float radius, t_ray *r)
{
	float	t[2];
	t_v3	len;
	float	tca;
	float	thc;
	float	d2;

	ft_sub_v3(pos, r->ori, len);
	tca = ft_dot_v3(len, r->dir);
	d2 = ft_dot_v3(len, len) - tca * tca;
	if (d2 > radius * radius)
		return (0);
	thc = sqrtf(radius * radius - d2);
	t[0] = tca - thc;
	t[1] = tca + thc;
	if (t[0] > t[1])
		swap_float(&t[0], &t[1]);
	if (t[0] < 0 && t[1] < 0)
		return (0);
	if (t[0] < 0 || (t[1] < t[0] && t[1] >= 0))
		t[0] = t[1];
	if (r->hit < t[0])
		return (0);
	r->hit = t[0];
	calc_normal(pos, r, t[0], t);
	return (1);
}
