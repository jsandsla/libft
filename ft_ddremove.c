/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:06:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:32:47 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ddremove(t_dd *dd, size_t i)
{
	if (i < dd->len && i < dd->da->a.len)
	{
		ft_dfree(&dd->ptr[i]);
		ft_daremove(dd->da, i);
		dd->len = dd->da->a.len;
		dd->ptr = dd->da->a.ptr;
	}
}
