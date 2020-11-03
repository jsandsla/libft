/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dappendc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:55:49 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 20:08:57 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dappendc(t_d *d, t_byte *mem, t_byte c, size_t len)
{
	t_err	error;
	size_t	actual_len;

	actual_len = 0;
	while (actual_len < len && mem[actual_len] != c)
		actual_len += 1;
	error = E_OK;
	if (d->max_len - d->len < actual_len)
		error = ft_dexpand(d, d->len + actual_len);
	if (error == E_OK)
	{
		ft_memcpy(d->ptr + d->len, mem, actual_len);
		d->len += actual_len;
	}
	return (error);
}
