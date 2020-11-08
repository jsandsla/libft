/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:44:14 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:39:36 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsappend(t_ds *ds, const char *mem, size_t n)
{
	t_err	error;
	t_d		d;
	size_t	len;

	ft_dinitm(&d, ds->s.m);
	len = ft_strnlen(mem, n);
	if (d.m->len)
		d.m->len -= 1;
	error = ft_dappend(&d, (t_byte *)mem, len);
	if (error)
	{
		if (d.m->len >= d.m->cap)
			error = ft_dexpand(&d, d.m->len + 1);
		if (error == E_OK)
		{
			d.m->len += 1;
			ft_sinitm(&ds->s, d.m);
		}
	}
	return (error);
}

t_err			ft_dsappendstr(t_ds *ds, const char *str)
{
	t_err	error;
	t_d		d;

	ft_dinitm(&d, ds->s.m);
	if (d.m->len)
		d.m->len -= 1;
	error = ft_dappend(&d, (t_byte *)str, ft_strlen(str));
	if (error)
	{
		if (d.m->len >= d.m->cap)
			error = ft_dexpand(&d, 1);
		if (error == E_OK)
		{
			d.m->len += 1;
			ft_sinitm(&ds->s, d.m);
		}
	}
	return (error);
}
