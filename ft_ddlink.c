/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:07:41 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:33:08 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddlink(t_dd *dd, t_da *da)
{
	t_err	error;

	error = E_INVALID_DATA_STRUCTURE;
	if (da->a.sz == sizeof(t_d))
	{
		error = E_OK;
		dd->da = da;
		dd->len = da->a.len;
		dd->ptr = da->a.ptr;
	}
	return (error);
}
