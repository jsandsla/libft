/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:54:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/13 21:19:55 by jsandsla         ###   ########.fr       */
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
