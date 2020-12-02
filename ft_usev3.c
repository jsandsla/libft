/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usev3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:43:45 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/30 12:59:39 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_dot_v3(t_v3 l, t_v3 r)
{
	float	result;

	result = l[0] * r[0] + l[1] * r[1] + l[2] * r[2];
	return (result);
}

void	ft_cross_v3_to(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = l[1] * r[2] - l[2] * r[1];
	out[1] = l[2] * r[0] - l[0] * r[2];
	out[2] = l[0] * r[1] - l[1] * r[0];
}

void	ft_lerp_v3(t_v3 l, t_v3 r, float t, t_v3 out)
{
	out[0] = l[0] * (1 - t) + r[0] * t;
	out[1] = l[1] * (1 - t) + r[1] * t;
	out[2] = l[2] * (1 - t) + r[2] * t;
}

float	ft_length_v3(t_v3 l)
{
	float	dot;

	dot = l[0] * l[0] + l[1] * l[1] + l[2] * l[2];
	if (dot >= 0.0000001f)
		dot = ft_sqrtf(dot);
	else
		dot = 0;
	return (dot);
}

void	ft_normalize_v3(t_v3 l)
{
	float	len;

	len = ft_length_v3(l);
	if (len > 0)
		ft_divvs_v3(l, len, l);
	else
		ft_make_v3(0, 0, 0, l);
}
