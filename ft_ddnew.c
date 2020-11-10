/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:52:53 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 20:10:26 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddnew(t_dd *dd, t_d **ppd)
{
	t_err	error;

	error = ft_ddnewinit(dd, ppd, NULL, 0);
	return (error);
}

t_err			ft_ddnewinit(t_dd *dd, t_d **ppd, t_byte *mem, size_t len)
{
	t_err	error;
	t_m		*m;
	t_d		*d;

	m = dd->da->a.m;
	error = ft_daappend(dd->da, NULL, 1);
	if (error == E_OK)
	{
		d = (t_d *)ft_da(dd->da, m->len - 1);
		error = ft_dinit(d, mem, len);
		if (error == E_OK)
			*ppd = d;
		else
			ft_daremove(dd->da, m->len - 1);
		dd->len = m->len;
		dd->ptr = (t_d *)m->ptr;
	}
	return (error);
}
