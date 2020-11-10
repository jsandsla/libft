/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:55:03 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 20:11:05 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddappend(t_dd *dd, t_d *d)
{
	t_err	error;
	t_m		*m;
	t_d		*pd;

	m = dd->da->a.m;
	error = ft_ddnew(dd, &pd);
	if (error == E_OK)
		*pd = *d;
	dd->len = m->len;
	dd->ptr = (t_d *)m->ptr;
	return (error);
}
