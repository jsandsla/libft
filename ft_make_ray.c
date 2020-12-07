/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:38:38 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/05 20:03:36 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_make_ray_dir(t_v3 pos, t_v3 dir, t_ray *r)
{
	ft_copy_v3(pos, r->ori);
	ft_copy_v3(dir, r->dir);
	ft_ext_normalize_v3(r->dir);
	r->inv_dir[0] = 1 / r->dir[0];
	r->inv_dir[1] = 1 / r->dir[1];
	r->inv_dir[2] = 1 / r->dir[2];
	r->hit = INFINITY;
}

void	ft_make_ray_point(t_v3 pos, t_v3 end, t_ray *r)
{
	t_v3	dir;

	ft_sub_v3(end, pos, dir);
	ft_make_ray_dir(pos, dir, r);
}
