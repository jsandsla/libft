/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:37:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 20:08:40 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dappend(t_d *d, t_byte *mem, size_t len)
{
	t_err	error;

	error = E_OK;
	if (d->max_len - d->len < len)
		error = ft_dexpand(d, d->len + len);
	if (error == E_OK)
	{
		if (mem)
			ft_memcpy(d->ptr + d->len, mem, len);
		d->len += len;
	}
	return (error);
}
