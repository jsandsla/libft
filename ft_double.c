/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:54:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/18 05:04:00 by jsandsla         ###   ########.fr       */
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

double	ft_fpow(double base, size_t power)
{
	double	num;

	num = 1.0;
	while (power > 0)
	{
		num *= base;
		power -= 1;
	}
	return (num);
}

double	ft_fabs(double num)
{
	t_ieee754	u;

	u.f = num;
	u.u &= ~(1ull << 63);
	return (u.f);
}

int		ft_epsilon(double l, double epsilon)
{
	return (l <= epsilon && l >= -epsilon);
}
