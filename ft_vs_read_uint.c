/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_read_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:47:38 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/11 17:05:09 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_vs_read_uint(t_vs *vs, t_uint *out)
{
	size_t	n;

	n = ft_vs_strtou(vs, out, 10, FT_VS_SYMX);
	ft_vsinc(vs, n);
	return (n);
}
