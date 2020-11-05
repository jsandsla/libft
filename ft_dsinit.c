/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:37:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:31:49 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsinit(t_ds *ds, char *mem, size_t len)
{
	t_err	error;

	ds->d = &ds->_d;
	error = ft_dinitex(ds->d, (t_byte *)mem, len, 1);
	if (error == E_OK)
	{
		ft_sinitn(&ds->s, (char *)ds->d->ptr, len);
		ds->d->len = ds->s.len;
	}
	return (error);
}

t_err			ft_dsinitd(t_ds *ds, t_d *d)
{
	t_err	error;

	error = ft_dsinit(ds, (char *)d->ptr, d->max_len);
	return (error);
}

t_err			ft_dsinitdlink(t_ds *ds, t_d *d)
{
	t_err	error;

	error = ft_dslink(ds, d);
	return (error);
}
