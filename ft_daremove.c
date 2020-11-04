/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:09:47 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 13:38:48 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_daremove(t_da *arr, size_t index)
{
	t_err	error;

	error = E_OUT_OF_BOUNDS;
	if (index < arr->len)
	{
		error = E_OK;
		arr->len -= 1;
		arr->d->len -= arr->sz;
		ft_memcpy(arr->d->ptr + index * arr->sz,
			arr->d->ptr + (index + 1) * arr->sz,
			arr->len - index);
	}
	return (error);
}
