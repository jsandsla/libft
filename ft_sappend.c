/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:15:20 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/11 17:54:23 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_sappend(t_s *s, const char *str)
{
	size_t	len;
	t_m		*m;

	m = s->m;
	len = m->len < m->cap ? m->cap - m->len - 1 : 0;
	if (len)
	{
		len = ft_strncpy((char *)m->ptr + m->len, str, len);
		m->len += len;
		m->ptr[m->len] = '\0';
	}
	return (len);
}

size_t			ft_sappendn(t_s *s, const char *str, size_t n)
{
	size_t	len;
	t_m		*m;

	m = s->m;
	len = m->len < m->cap ? FT_MIN(m->cap - m->len - 1, n) : 0;
	if (len)
	{
		len = ft_strncpy((char *)m->ptr + m->len, str, len);
		m->len += len;
		m->ptr[m->len] = '\0';
	}
	return (len);
}

size_t			ft_sappendraw(t_s *s, const char *str, size_t n)
{
	size_t	len;
	t_m		*m;

	m = s->m;
	len = m->len < m->cap ? FT_MIN(m->cap - m->len - 1, n) : 0;
	if (len)
	{
		ft_memcpy((char *)m->ptr + m->len, str, len);
		m->len += len;
		m->ptr[m->len] = '\0';
	}
	return (len);
}

size_t			ft_sappendc(t_s *s, char c)
{
	size_t	len;

	len = ft_sappendn(s, &c, 1);
	return (len);
}

size_t			ft_sappendm(t_s *s, t_m *m)
{
	size_t	len;

	len = ft_sappendn(s, (char *)m->ptr, m->len);
	return (len);
}
