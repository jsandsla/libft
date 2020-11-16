/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:54:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/17 04:40:20 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinf(double f)
{
	t_ieee754	ieee754;

	ieee754.f = f;
	return (((unsigned)(ieee754.u >> 32) & 0x7fffffff) == 0x7ff00000 &&
			((unsigned)ieee754.u == 0));
}

int		ft_isnan(double f)
{
	t_ieee754	ieee754;

	ieee754.f = f;
	return (((unsigned)(ieee754.u >> 32) & 0x7fffffff) +
			((unsigned)ieee754.u != 0) > 0x7ff00000);
}

double	ft_modf(double x, double *iptr)
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
			u.u &= 1ULL << 63;
		*iptr = e >= 52 ? x : u.f;
		fract = e >= 52 ? u.f : x;
	}
	else
	{
		cond = (u.u & ((-1ULL >> 12) >> e)) == 0;
		u.u &= cond ? 1ULL << 63 : ~((-1ULL >> 12) >> e);
		*iptr = cond ? x : u.f;
		fract = cond ? u.f : x - u.f;
	}
	return (fract);
}
