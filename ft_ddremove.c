/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:06:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 21:52:07 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddremove(t_dd *dd, size_t i)
{
	t_err	error;
	t_d		d;

	error = E_OUT_OF_BOUNDS;
	if (i < dd->len)
	{
		d = dd->ptr[i];
		error = ft_daremove(&dd->da, i);
		if (error == E_OK)
		{
			ft_dfree(&d);
			dd->len -= 1;
			dd->ptr = (t_d *)dd->da.ptr;
		}
	}
	return (error);
}
