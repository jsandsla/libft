/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 00:28:40 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/14 00:33:25 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_mmove(t_m *m, void *mem, size_t len)
{
	if (m->ptr)
		ft_memmove(mem, m->ptr, FT_MIN(len, m->len) * m->sz);
	m->ptr = mem;
	m->len = FT_MIN(len, m->len);
	m->cap = len;
	return (m->len);
}
