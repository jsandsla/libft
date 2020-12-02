/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:12:53 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/02 16:35:03 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_plane_ray_test(t_v3 pos, t_v3 normal, t_ray *r)
{
	float	denom;
	t_v3	c;

	denom = ft_dot_v3(normal, r->dir);
	if (denom > FT_EPSF || denom < -FT_EPSF)
	{
		ft_sub_v3(pos, r->ori, c);
		r->hit = ft_dot_v3(c, normal) / denom;
		if (r->hit > 0)
		{
			ft_copy_v3(normal, r->hitnormal);
			return (1);
		}
	}
	return (0);
}
