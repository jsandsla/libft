/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:49:54 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/30 12:59:19 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

float	ft_ext_length_v3(t_v3 l)
{
	float	dot;

	dot = l[0] * l[0] + l[1] * l[1] + l[2] * l[2];
	if (dot >= 0.0000001f)
		dot = sqrtf(dot);
	else
		dot = 0;
	return (dot);
}

void	ft_ext_normalize_v3(t_v3 l)
{
	float	len;

	len = ft_ext_length_v3(l);
	if (len > 0)
		ft_divvs_v3(l, len, l);
	else
		ft_make_v3(0, 0, 0, l);
}

float	ft_ext_length_v4(t_v4 l)
{
	float	dot;

	dot = l[0] * l[0] + l[1] * l[1] + l[2] * l[2] + l[3] * l[3];
	if (dot >= 0.0000001f)
		dot = sqrtf(dot);
	else
		dot = 0;
	return (dot);
}

void	ft_ext_normalize_v4(t_v4 l)
{
	float	len;

	len = ft_ext_length_v4(l);
	if (len > 0)
		ft_divvs_v4(l, len, l);
	else
		ft_make_v4(0, 0, 0, l);
}
