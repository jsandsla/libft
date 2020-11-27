/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_strtod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:39:32 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 20:15:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	exponent(t_vs *vs, double *out)
{
	int		exp;
	char	c;

	exp = 0;
	while ((c = ft_vs(vs, 0)) && IS_DIGIT(c))
	{
		*out *= 10;
		*out += (c - '0');
		exp += 1;
	}
	if (exp)
		*out /= ft_fpow(10.0, exp);
}

size_t			ft_vs_strtod(t_vs *vs, double *out)
{
	char	c;
	size_t	start;
	int		sign;

	*out = 0;
	start = vs->offset;
	sign = ft_vs_inc_if(vs, '-');
	ft_vs_inc_if(vs, '+');
	while ((c = ft_vs(vs, 0)) && IS_DIGIT(c))
	{
		*out *= 10;
		*out += (c - '0');
	}
	if (ft_vs_inc_if(vs, '.'))
		exponent(vs, out);
	start = vs->offset - start;
	vs->offset -= start;
	*out = sign ? -*out : *out;
	return (start);
}
