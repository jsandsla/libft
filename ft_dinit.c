/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:22:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 12:20:32 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dinit(t_d *d, t_byte *mem, size_t len)
{
	t_err	error;

	error = ft_dinitex(d, mem, len, 0);
	return (error);
}

t_err			ft_dinitex(t_d *d, t_byte *mem, size_t len, size_t reserve_len)
{
	t_err	error;

	error = E_OK;
	d->len = 0;
	d->max_len = 0;
	d->reserve_len = reserve_len;
	d->ptr = 0;
	if (mem)
		error = ft_dappend(d, mem, len);
	else if (len)
		error = ft_dexpand(d, len);
	return (error);
}
