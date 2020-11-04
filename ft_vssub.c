/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vssub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:49:40 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 16:00:20 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vs			ft_vssub(t_vs *vs, size_t offset, size_t len)
{
	t_vs	newvs;

	newvs = *vs;
	offset = FT_MIN(offset, vs->len - vs->offset);
	len = FT_MIN(len, vs->len - (vs->offset + offset));
	newvs.ptr += offset;
	newvs.offset = 0;
	newvs.len = len;
	return (newvs);
}
