/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dainit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:10:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:32:50 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dainit(t_da *da, size_t sz, void *elems, size_t count)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		da->d = &da->_d;
		error = ft_dinit(da->d, elems, sz * count);
		if (error == E_OK)
		{
			da->len = da->d->len / sz;
			da->sz = sz;
			da->ptr = da->d->ptr;
		}
	}
	return (error);
}
