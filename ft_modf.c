/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:03:23 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/23 20:21:44 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_modf(double x, double *int_part)
{
	t_ieee754	u;
	int			e;
	double		fract;
	int			cond;

	u.f = x;
	e = (int)(u.u >> 52 & 0x7ff) - 0x3ff;
	if (e >= 52 || e < 0)
	{
		if (!(e == 0x400 && u.u << 12 != 0))
			u.u &= 1ull << 63;
		*int_part = e >= 52 ? x : u.f;
		fract = e >= 52 ? u.f : x;
	}
	else
	{
		cond = (u.u & ((-1ull >> 12) >> e)) == 0;
		u.u &= cond ? 1ull << 63 : ~((-1ull >> 12) >> e);
		*int_part = cond ? x : u.f;
		fract = cond ? u.f : x - u.f;
	}
	return (fract);
}
