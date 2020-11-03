/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dainit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:10:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:05:14 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dainit(t_da *arr, size_t sz, void *elems, size_t count)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		error = ft_dinit(&arr->d, elems, sz * count);
		if (error == E_OK)
		{
			arr->len = arr->d.len / sz;
			arr->sz = sz;
			arr->ptr = arr->d.ptr;
		}
	}
	return (error);
}
