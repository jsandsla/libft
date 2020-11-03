/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddnewinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:01:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:09:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddnewinit(t_dd *dd, t_d **ppd, t_byte *mem, size_t len)
{
	t_err	error;

	error = ft_daappend(&dd->da, 0, 1);
	if (error == E_OK)
	{
		*ppd = (t_d *)ft_da(&dd->da, dd->da.len - 1);
		error = ft_dinit(*ppd, mem, len);
		if (error == E_OK)
			dd->len += 1;
		else
		{
			ft_daremove(&dd->da, dd->da.len - 1);
			*ppd = 0;
		}
		dd->ptr = dd->da.ptr;
	}
	return (error);
}
