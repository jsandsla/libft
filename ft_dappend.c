/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:37:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:37:48 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dappend(t_d *d, t_byte *mem, size_t len)
{
	t_err	error;

	error = E_OK;
	if (d->m->cap - d->m->len < len)
		error = ft_dexpand(d, d->m->len + len);
	if (error == E_OK)
	{
		if (mem)
			ft_memcpy(d->m->ptr + d->m->len, mem, len);
		d->m->len += len;
	}
	return (error);
}

t_err			ft_dappendc(t_d *d, t_byte *mem, t_byte c, size_t len)
{
	t_err	error;
	size_t	actual_len;

	actual_len = 0;
	while (actual_len < len && mem[actual_len] != c)
		actual_len += 1;
	error = ft_dappend(d, mem, actual_len);
	return (error);
}
