/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usev4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:26:35 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 18:04:08 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_dot_v4(t_v4 l, t_v4 r)
{
	float	result;

	result = l[0] * r[0] + l[1] * r[1] + l[2] * r[2] + l[3] * r[3];
	return (result);
}

void	ft_lerp_v4(t_v4 l, t_v4 r, float t, t_v4 out)
{
	out[0] = l[0] * (1 - t) + r[0];
	out[1] = l[1] * (1 - t) + r[1];
	out[2] = l[2] * (1 - t) + r[2];
	out[3] = l[3] * (1 - t) + r[3];
}

float	ft_length_v4(t_v4 l)
{
	float	dot;

	dot = l[0] * l[0] + l[1] * l[1] + l[2] * l[2] + l[3] * l[3];
	if (dot >= 0.0000001f)
		dot = ft_sqrtf(dot);
	else
		dot = 0;
	return (dot);
}

void	ft_normalize_v4(t_v4 l)
{
	float	len;

	len = ft_length_v4(l);
	if (len > 0)
		ft_divvs_v4(l, len, l);
	else
		ft_make_v4(l, 0, 0, 0);
}
