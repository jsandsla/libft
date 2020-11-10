/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:37:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:45:07 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dappend(t_d *d, t_byte *mem, size_t len)
{
	t_m		*m;
	t_err	error;

	m = d->m;
	error = E_OK;
	if (m->cap - m->len < len)
		error = ft_dexpand(d, m->len + len);
	if (error == E_OK)
	{
		if (mem)
			ft_memcpy(m->ptr + m->len, mem, len);
		m->len += len;
	}
	return (error);
}

t_err			ft_dappendm(t_d *d, t_m *m)
{
	t_err	error;

	error = E_INVALID_DATA_STRUCTURE;
	if (d->m->sz == m->sz)
		error = ft_dappend(d, m->ptr, m->len);
	return (error);
}
