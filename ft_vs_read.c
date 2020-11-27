/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:47:38 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 16:36:54 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_vs_read_int(t_vs *vs, int *out)
{
	size_t	n;

	n = ft_vs_strtol(vs, out, 10, FT_VS_SYMX);
	ft_vs_inc(vs, n);
	ft_vs_skip_ws(vs);
	return (n);
}

size_t			ft_vs_read_uint(t_vs *vs, t_uint *out)
{
	size_t	n;

	n = ft_vs_strtou(vs, out, 10, FT_VS_SYMX);
	ft_vs_inc(vs, n);
	ft_vs_skip_ws(vs);
	return (n);
}

size_t			ft_vs_read_int_unsign(t_vs *vs, int *out)
{
	size_t	n;
	t_uint	uout;

	n = ft_vs_strtou(vs, &uout, 10, FT_VS_SYMX);
	*out = (int)uout;
	ft_vs_inc(vs, n);
	ft_vs_skip_ws(vs);
	return (n);
}

size_t			ft_vs_read_double(t_vs *vs, double *out)
{
	size_t	n;

	n = ft_vs_strtod(vs, out);
	ft_vs_inc(vs, n);
	ft_vs_skip_ws(vs);
	return (n);
}

size_t			ft_vs_read_float(t_vs *vs, float *out)
{
	size_t	n;
	double	d;

	n = ft_vs_strtod(vs, &d);
	*out = (float)d;
	ft_vs_inc(vs, n);
	ft_vs_skip_ws(vs);
	return (n);
}
