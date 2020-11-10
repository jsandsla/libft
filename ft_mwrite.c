/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:09:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:09:48 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_mwrite(t_m *m, size_t offset, void *mem, size_t len)
{
	offset = FT_MIN(offset, m->cap);
	len = FT_MIN(len, m->cap - offset);
	if (len)
		ft_memcpy(m->ptr + offset * m->sz, mem, len * m->sz);
	m->len = FT_MAX(m->len, offset + len);
	return (len);
}

size_t			ft_mwriteb(t_m *m, size_t offset, t_byte b)
{
	size_t	len;

	len = (offset < m->cap);
	if (len)
	{
		m->ptr[offset * m->sz] = b;
		m->len = FT_MAX(m->len, offset + 1);
	}
	return (len);
}
