/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:54:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/17 05:20:49 by jsandsla         ###   ########.fr       */
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

double	ft_fpow(double num, size_t power)
{
	while (power > 1)
	{
		num *= num;
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
