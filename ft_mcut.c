/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mcut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:36:26 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:11:38 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_mcut(t_m *m, size_t offset, size_t len)
{
	offset = FT_MIN(offset, m->len);
	len = FT_MIN(len, m->len - offset);
	if (offset + len < m->len)
		ft_memcpy(m->ptr + offset * m->sz,
			m->ptr + (offset + len) * m->sz,
			m->len - (offset + len) * m->sz);
	m->len -= len;
	return (len);
}
