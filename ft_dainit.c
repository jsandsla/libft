/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dainit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:10:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 13:43:22 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dainit(t_da *da, size_t sz, void *elems, size_t max_len)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		da->d = &da->_d;
		error = ft_dinit(da->d, elems, sz * max_len);
		if (error == E_OK)
			ft_ainit(&da->a, sz, da->d->ptr, max_len);
	}
	return (error);
}

t_err			ft_dainitd(t_da *da, size_t sz, t_d *d)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		ft_dainit(da, sz, d->ptr, d->max_len / sz);
		da->a.len = d->len / sz;
	}
	return (error);
}

t_err			ft_dainitdlink(t_da *da, size_t sz, t_d *d)
{
	t_err	error;

	error = ft_dalink(da, sz, d);
	return (error);
}
