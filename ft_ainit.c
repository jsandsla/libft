/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:50:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 00:52:55 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ainit(t_a *a, size_t sz, void *mem, size_t max_len)
{
	a->sz = sz;
	a->ptr = mem;
	a->max_len = max_len;
	a->len = 0;
}

void			ft_ainitd(t_a *a, size_t sz, t_d *d)
{
	a->sz = sz;
	a->ptr = d->ptr;
	a->max_len = d->max_len / a->sz;
	a->len = d->len / a->sz;
}
