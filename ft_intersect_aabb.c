/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_aabb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:44:41 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/05 20:04:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_aabb_ray_test(t_v3 min, t_v3 max, t_ray *r)
{
	t_v3	t1;
	t_v3	t2;
	float	t[2];

	t1[0] = (min[0] - r->ori[0]) * r->inv_dir[0];
	t2[0] = (max[0] - r->ori[0]) * r->inv_dir[0];
	t[0] = FT_MIN(t1[0], t2[0]);
	t[1] = FT_MAX(t1[0], t2[0]);
	t1[1] = (min[1] - r->ori[1]) * r->inv_dir[1];
	t2[1] = (max[1] - r->ori[1]) * r->inv_dir[1];
	t[0] = FT_MAX(t[0], FT_MIN(t1[1], t2[1]));
	t[1] = FT_MIN(t[1], FT_MAX(t1[1], t2[1]));
	t1[2] = (min[2] - r->ori[2]) * r->inv_dir[2];
	t2[2] = (max[2] - r->ori[2]) * r->inv_dir[2];
	t[0] = FT_MAX(t[0], FT_MIN(t1[2], t2[2]));
	t[1] = FT_MIN(t[1], FT_MAX(t1[2], t2[2]));
	if (t[1] < 0 || t[1] < t[0])
		return (0);
	if (t[0] < 0)
		t[0] = t[1];
	if (r->hit < t[0])
		return (0);
	r->hit = t[0];
	return (1);
}
