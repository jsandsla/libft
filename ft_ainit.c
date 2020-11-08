/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:50:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:36:26 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ainit(t_a *a, size_t sz, void *mem, size_t len,
	size_t max_len)
{
	a->m = &a->_m;
	ft_minit(a->m, mem, len * sz, max_len * sz);
	a->sz = sz;
	a->max_len = max_len;
	a->len = len;
}

void			ft_ainitm(t_a *a, size_t sz, t_m *m)
{
	a->m = m;
	a->sz = sz;
	a->max_len = m->cap / a->sz;
	a->len = m->len / a->sz;
}
