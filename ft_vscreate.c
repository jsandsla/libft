/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vscreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:17 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 15:37:33 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vs			ft_vscreate(t_ds *ds, size_t offset, size_t len)
{
	t_vs	vs;

	offset = FT_MIN(offset, ds->len);
	vs.ds = ds;
	vs.ptr = ds->ptr + offset;
	vs.offset = 0;
	vs.len = FT_MIN(ds->len - offset, len);
	return (vs);
}
