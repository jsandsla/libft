/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:07:47 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 16:08:45 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_fabsf(float num)
{
	t_ieee754f	u;

	u.f = num;
	u.u &= ~(1ull << 31);
	return (u.f);
}

int		ft_epsf(float l, float epsilon)
{
	return (l <= epsilon && l >= -epsilon);
}

float	ft_copysignf(float x, float y)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		x = -x;
	return (x);
}
