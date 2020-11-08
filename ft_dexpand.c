/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dexpand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:25:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/08 22:35:18 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dexpand(t_d *d, size_t required)
{
	size_t	new_cap;
	t_byte	*new_ptr;

	new_cap = (d->m->cap) ? (d->m->cap * 2) : (16);
	if (new_cap < required)
		new_cap = ft_to_powof2(required);
	new_ptr = malloc(new_cap);
	if (new_ptr)
	{
		if (d->m->ptr)
		{
			ft_memcpy(new_ptr, d->m->ptr, d->m->len);
			free(d->m->ptr);
		}
		d->m->ptr = new_ptr;
		d->m->cap = new_cap;
	}
	return (new_ptr != NULL ? E_OK : E_MALLOC);
}
