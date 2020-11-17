/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:03:23 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/17 05:19:28 by jsandsla         ###   ########.fr       */
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

static	double	floor(double n)
{
	ft_modf(n, &n);
	return (n);
}

static	double	ceil(double n)
{
	ft_modf(n, &n);
	return (n + 1);
}

static	double	round(doubel n)
{
	if ((int)(ft_modf(n, &n) * 10) >= 5)
		n += 1;
	return (n);
}

double			ft_modf_rounded(double x, double *int_part, size_t precision)
{
	double	power;
	double	fract_part;
	double	fract_raised;
	double	fract_raised_and_rounded;
	double	fract_raised_int;

	power = precision ? 1.0 : ft_fpow(10.0, precision);
	fract_part = ft_fabs(ft_modf(original, int_part));
	fract_raised = fract_part * power;
	if ((int)(ft_modf(fract_raised, &fract_raised_int) * 10) == 5)
		fract_raised_and_rounded = (long)fract_raised_int & 1 ?
			floor(fract_raised) : ceil(fract_raised);
	else
		fract_raised_and_rounded = round(fract_raised);
	if (fract_raised_and_rounded >= power)
	{
		fract_raised_and_rounded -= power;
		*int_part = *int_part < 0 ? *int_part - 1 : *int_part + 1;
	}
	return (fract_raised_and_rounded);
}
