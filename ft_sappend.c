/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:15:20 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/08 22:14:19 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_sappend(t_s *s, const char *str)
{
	size_t	len;

	len = s->max_len - s->len;
	if (len)
		len = ft_strncpy((char *)s->m->ptr + s->len, str, len);
	s->len += len;
	s->m->len += len;
	s->m->ptr[s->len] = '\0';
	return (len);
}

size_t			ft_sappendn(t_s *s, const char *str, size_t n)
{
	size_t	len;

	len = FT_MIN(s->max_len - s->len, n);
	if (len)
		len = ft_strncpy((char *)s->m->ptr + s->len, str, len);
	s->len += len;
	s->m->len += len;
	s->m->ptr[s->len] = '\0';
	return (len);
}

size_t			ft_sappendc(t_s *s, char c)
{
	size_t	len;

	len = ft_sappendn(s, &c, 1);
	return (len);
}

size_t			ft_sappends(t_s *s, t_s *ss)
{
	size_t	len;

	len = ft_sappendn(s, (char *)ss->m->ptr, ss->len);
	return (len);
}

size_t			ft_sappendm(t_s *s, t_m *m)
{
	size_t	len;

	len = ft_sappendn(s, (char *)m->ptr, m->len ? m->len - 1 : 0);
	return (len);
}
