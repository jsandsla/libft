/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:53:06 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/08 21:50:25 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_aappend(t_a *a, void *elems, size_t count)
{
	count = FT_MIN(count, a->max_len - a->len);
	ft_mappend(a->m, elems, count * a->sz);
	a->len += count;
	return (count);
}

size_t			ft_aappenda(t_a *a, t_a *aa)
{
	size_t	count;

	count = ft_aappend(a, aa->m->ptr, aa->len);
	return (count);
}

size_t			ft_aappendm(t_a *a, t_m *m)
{
	size_t	count;

	count = ft_aappend(a, m->ptr, m->len / a->sz);
	return (count);
}
