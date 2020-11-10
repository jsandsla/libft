/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:20:34 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:17:04 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_mappend(t_m *m, void *mem, size_t len)
{
	len = FT_MIN(len, m->cap - m->len);
	if (len)
		ft_memcpy(m->ptr + m->len * m->sz, mem, len * m->sz);
	m->len += len;
	return (len);
}

size_t			ft_mappendm(t_m *m, t_m *mm)
{
	size_t	len;

	if (m->sz == mm->sz)
		len = ft_mappend(m, mm->ptr, mm->len);
	else
		len = 0;
	return (len);
}

size_t			ft_mappendb(t_m *m, t_byte b)
{
	size_t	len;

	len = ft_mappend(m, &b, 1);
	return (len);
}
