/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:06:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 20:11:30 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ddremove(t_dd *dd, size_t i)
{
	if (i < dd->len && i < dd->da->a.m->len)
	{
		ft_dfree(&dd->ptr[i]);
		ft_daremove(dd->da, i);
		dd->len = dd->da->a.m->len;
		dd->ptr = (t_d *)dd->da->a.m->ptr;
	}
}
