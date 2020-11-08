/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:55:29 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:40:17 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ddinit(t_dd *dd)
{
	dd->da = &dd->_da;
	ft_dainit(dd->da, sizeof(t_d), 0, 0, 0);
	dd->len = 0;
	dd->ptr = 0;
}

void			ft_ddinitda(t_dd *dd, t_da *da)
{
	dd->da = da;
	dd->len = da->a.len;
	dd->ptr = (t_d *)da->a.m->ptr;
}
