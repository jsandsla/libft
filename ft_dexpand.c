/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dexpand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:25:46 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:04:52 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dexpand(t_d *d, size_t required)
{
	size_t	new_max_len;
	t_byte	*new_ptr;

	new_max_len = (d->max_len) ? (d->max_len * 2) : (16);
	if (new_max_len < required)
		new_max_len = ft_next_powof2(required);
	new_ptr = malloc(new_max_len + d->reserve_len);
	if (new_ptr)
	{
		if (d->ptr)
		{
			ft_memcpy(new_ptr, d->ptr, d->len);
			free(d->ptr);
		}
		d->ptr = new_ptr;
		d->max_len = new_max_len;
	}
	return (new_ptr != NULL ? E_OK : E_MALLOC);
}
