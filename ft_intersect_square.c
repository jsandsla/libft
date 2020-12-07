/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:53:26 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/03 15:53:45 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		orient(t_v3 p, t_v3 p1, t_v3 p2, t_v3 normal)
{
	t_v3	l;
	t_v3	r;
	t_v3	cross;
	int		sign;

	ft_sub_v3(p1, p, l);
	ft_sub_v3(p2, p, r);
	ft_cross_v3_to(l, r, cross);
	sign = ft_dot_v3(cross, normal) < 0 ? -1 : 1;
	return (sign);
}

int				ft_square_ray_test(t_v3 pos[4], t_v3 normal, t_ray *r)
{
	t_v3	p;
	int		ret;
	t_ray	rr;

	rr = *r;
	if (ft_plane_ray_test(pos[0], normal, &rr) && r->hit > rr.hit)
	{
		ft_mulvs_add_v3(rr.dir, rr.hit, rr.ori, p);
		ret = orient(p, pos[0], pos[1], normal);
		if (ret == orient(p, pos[1], pos[2], normal) &&
			ret == orient(p, pos[2], pos[3], normal) &&
			ret == orient(p, pos[3], pos[0], normal))
		{
			r->hit = rr.hit;
			return (1);
		}
	}
	return (0);
}
