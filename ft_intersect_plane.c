/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:12:53 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/03 16:00:08 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_plane_ray_test(t_v3 pos, t_v3 normal, t_ray *r)
{
	float	denom;
	t_v3	c;
	float	hit;

	denom = ft_dot_v3(normal, r->dir);
	if (denom > FT_EPSF || denom < -FT_EPSF)
	{
		ft_sub_v3(pos, r->ori, c);
		hit = ft_dot_v3(c, normal) / denom;
		if (hit > 0)
		{
			if (r->hit < hit)
				return (0);
			r->hit = hit;
			ft_copy_v3(normal, r->hitnormal);
			return (1);
		}
	}
	return (0);
}
