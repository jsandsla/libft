/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usev4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:26:35 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 17:10:18 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_dot_v4(t_v4 *l, t_v4 *r)
{
	float	result;

	result = l->x * r->x + l->y * r->y + l->z * r->z + l->w * r->w;
	return (result);
}

void	ft_lerp_v4(t_v4 *l, t_v4 *r, float t, t_v4 *out)
{
	out->x = l->x * (1 - t) + r->x;
	out->y = l->y * (1 - t) + r->y;
	out->z = l->z * (1 - t) + r->z;
	out->w = l->w * (1 - t) + r->w;
}

float	ft_length_v4(t_v4 *l)
{
	float	dot;

	dot = l->x * l->x + l->y * l->y + l->z * l->z + l->w * l->w;
	if (dot >= 0.0000001f)
		dot = ft_sqrtf(dot);
	else
		dot = 0;
	return (dot);
}

void	ft_normalize_v4(t_v4 *l)
{
	float	len;

	len = ft_length_v4(l);
	if (len > 0)
		ft_divvs_v4(l, len, l);
	else
		*l = (t_v4){0, 0, 0, 0};
}
