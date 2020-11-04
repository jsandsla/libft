/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dslink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:59:53 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 23:28:18 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dslink(t_ds *ds, t_d *d)
{
	t_err	error;

	error = E_OK;
	if (d != NULL)
	{
		if (d->reserve_len < 1)
		{
			d->reserve_len = 1;
			if (d->ptr)
				error = ft_dexpand(d, 0);
		}
		if (error == E_OK)
		{
			ds->d = d;
			ds->len = d->len;
			ds->ptr = (char *)d->ptr;
			if (ds->ptr)
				ds->ptr[ds->len] = '\0';
		}
	}
	else
		error = ft_dslink(ds, &ds->_d);
	return (error);
}
