/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:22:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/08 22:32:06 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dinit(t_d *d, t_byte *mem, size_t len)
{
	t_err	error;

	error = E_OK;
	d->m = &d->_m;
	ft_minit(d->m, 0, 0, 0);
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
