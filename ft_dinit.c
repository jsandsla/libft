/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:22:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/13 21:09:16 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dinit(t_d *d, t_byte *mem, size_t len)
{
	t_err	error;

	error = E_OK;
	d->m = &d->local_m;
	ft_minit(d->m, 1, NULL, 0);
	if (mem)
		error = ft_dappend(d, mem, len);
	else if (len)
		error = ft_dexpand(d, len);
	return (error);
}

void			ft_dinitm(t_d *d, t_m *m)
{
	d->m = m;
}
