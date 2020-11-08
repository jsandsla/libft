/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:57:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:36:53 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_aremove(t_a *a, size_t i)
{
	if (i < a->len)
		a->len -= !!ft_mcut(a->m, i * a->sz, a->sz);
}

void			ft_aremovep(t_a *a, void *p)
{
	int		success;

	success = ((size_t)p >= (size_t)a->m->ptr &&
		(size_t)p < (size_t)a->m->ptr + a->len * a->sz);
	success = (success && ((size_t)p - (size_t)a->m->ptr) % a->sz == 0);
	if (success)
		ft_aremove(a, ((size_t)p - (size_t)a->m->ptr) / a->sz);
}
