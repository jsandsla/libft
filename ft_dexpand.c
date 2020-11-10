/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dexpand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:25:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:40:29 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dexpand(t_d *d, size_t required)
{
	t_m		*m;
	size_t	new_cap;
	t_byte	*new_ptr;

	m = d->m;
	new_cap = (m->cap) ? (m->cap * 2) : (16);
	if (new_cap < required)
		new_cap = ft_to_powof2(required);
	new_ptr = malloc(new_cap * m->sz);
	if (new_ptr)
	{
		if (m->ptr)
		{
			ft_memcpy(new_ptr, m->ptr, m->len * m->sz);
			free(m->ptr);
		}
		m->ptr = new_ptr;
		m->cap = new_cap;
	}
	return (new_ptr != NULL ? E_OK : E_MALLOC);
}
