/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:57:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:19:54 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_aremove(t_a *a, size_t i)
{
	ft_mcut(a->m, i, 1);
}

void			ft_aremovep(t_a *a, void *p)
{
	int		success;

	success = ((size_t)p >= (size_t)a->m->ptr &&
		(size_t)p < (size_t)a->m->ptr + a->m->len * a->m->sz);
	success = (success && ((size_t)p - (size_t)a->m->ptr) % a->m->sz == 0);
	if (success)
		ft_mcut(a->m, ((size_t)p - (size_t)a->m->ptr) / a->m->sz, 1);
}
