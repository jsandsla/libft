/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usev3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:43:45 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 15:50:04 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_dot_v3(t_v3 *l, t_v3 *r)
{
	float	result;

	result = l->x * r->x + l->y * r->y + l->z * r->z;
	return (result);
}

void	ft_cross_v3(t_v3 *l, t_v3 *r, t_v3 *out)
{
	out->x = l->y * r->z - l->z * r->y;
	out->y = l->z * r->x - l->x * r->z;
	out->z = l->x * r->y - l->y * r->x;
}

void	ft_lerp_v3(t_v3 *l, t_v3 *r, float t, t_v3 *out)
{
	out->x = l->x * (1 - t) + r->x * t;
	out->y = l->y * (1 - t) + r->y * t;
	out->z = l->z * (1 - t) + r->z * t;
}

float	ft_length_v3(t_v3 *l)
{
	float	dot;

	dot = l->x * l->x + l->y * l->y + l->z * l->z;
	if (dot >= 0.0000001f)
		dot = ft_sqrtf(dot);
	else
		dot = 0;
	return (dot);
}

void	ft_normalize_v3(t_v3 *l)
{
	float	len;

	len = ft_length_v3(l);
	if (len > 0)
		ft_divvs_v3(l, len, l);
	else
		*l = (t_v3){0, 0, 0};
}
