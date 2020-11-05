/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:57:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:27:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_aremove(t_a *a, size_t i)
{
	if (i < a->len)
	{
		ft_memcpy((t_byte *)a->ptr + i * a->sz,
			(t_byte *)a->ptr + (i + 1) * a->sz,
			a->len - i - 1);
		a->len -= 1;
	}
}

void			ft_aremovep(t_a *a, void *p)
{
	int		success;

	success = ((size_t)p >= (size_t)a->ptr &&
		(size_t)p < (size_t)a->ptr + a->len * a->sz);
	success = (success && ((size_t)p - (size_t)a->ptr) % a->sz == 0);
	if (success)
		ft_aremove(a, ((size_t)p - (size_t)a->ptr) / a->sz);
}
