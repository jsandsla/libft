/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf_rounded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:33:07 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/23 21:45:23 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	double	round(double n)
{
	if ((long)(ft_modf(n, &n) * 10) >= 5)
		n += n < 0 ? -1 : 1;
	return (n);
}

static	double	g_round_table[10] =
{
	1, 0, 0, 1, 0, 1, 0, 1, 1, 0,
};

double			ft_modf_rounded(double x, double *int_part, size_t precision)
{
	double	power;
	double	fract_part;
	double	fract_raised;
	double	fract_raised_and_rounded;
	double	fract_raised_int;

	power = !precision ? 1.0 : ft_fpow(10.0, precision);
	fract_part = ft_fabs(ft_modf(x, int_part));
	fract_raised = fract_part * power;
	fract_raised_and_rounded = fract_raised;
	if (ft_epsilon(ft_modf(fract_raised, &fract_raised_int) - 0.5, 0.000000001))
		fract_raised_and_rounded += g_round_table[(long)fract_raised_int % 10];
	else
		fract_raised_and_rounded = round(fract_raised);
	if (fract_raised_and_rounded >= power)
	{
		fract_raised_and_rounded -= power;
		*int_part = *int_part < 0 ? *int_part - 1 : *int_part + 1;
	}
	return (fract_raised_and_rounded);
}
