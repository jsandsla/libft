/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:49:40 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 15:36:59 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vs			ft_vs_sub(t_vs *vs, size_t offset, size_t len)
{
	t_vs	newvs;

	offset = FT_MIN(offset, vs->len - vs->offset);
	len = FT_MIN(len, vs->len - (vs->offset + offset));
	newvs.ptr = vs->ptr + offset;
	newvs.len = len;
	newvs.offset = 0;
	return (newvs);
}
