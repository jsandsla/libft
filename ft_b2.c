/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:52:32 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 13:02:47 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bfree(void *pptr)
{
	if (*(void **)pptr)
		free((int *)*(void **)pptr - 2);
	*(void **)pptr = 0;
}

t_m		ft_b_to_m(void *ptr, int sz)
{
	t_m		m;

	m.sz = sz;
	if (sz)
	{
		m.len = ft_blen(ptr) / sz;
		m.cap = ft_bcap(ptr) / sz;
	}
	m.ptr = ptr;
	return (m);
}
