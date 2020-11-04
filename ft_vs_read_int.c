/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_read_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:47:38 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 22:10:06 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_vs_read_int(t_vs *vs, int *out)
{
	size_t	n;

	n = ft_vs_strtol(vs, out, 10, FT_VS_SYMX);
	ft_vsinc(vs, n);
	return (n);
}
