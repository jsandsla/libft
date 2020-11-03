/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:16:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:05:25 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_daappend(t_da *arr, void *elems, size_t count)
{
	t_err	error;

	error = ft_dappend(&arr->d, elems, count * arr->sz);
	if (error == E_OK)
	{
		arr->len = arr->d.len / arr->sz;
		arr->ptr = arr->d.ptr;
	}
	return (error);
}
