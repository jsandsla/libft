/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:15:20 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 01:23:01 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_sappend(t_s *s, const char *str)
{
	size_t	len;

	len = s->max_len - s->len;
	len = ft_strnlen(str, len);
	if (len)
		ft_memcpy(s->ptr + s->len, str, len);
	s->len += len;
	s->ptr[s->len] = '\0';
	return (len);
}

size_t			ft_sappendn(t_s *s, const char *str, size_t n)
{
	size_t	len;

	len = FT_MIN(s->max_len - s->len, n);
	len = ft_strnlen(str, len);
	if (len)
		ft_memcpy(s->ptr + s->len, str, len);
	s->len += len;
	s->ptr[s->len] = '\0';
	return (len);
}

size_t			ft_sappendd(t_s *s, t_d *d)
{
	size_t	len;

	len = FT_MIN(s->max_len - s->len, d->len);
	if (len)
		ft_memcpy(s->ptr + s->len, d->ptr, len);
	s->len += len;
	s->ptr[s->len] = '\0';
}

size_t			ft_sappends(t_s *s, t_s *ss)
{
	size_t	len;

	len = FT_MIN(s->max_len - s->len, ss->len);
	if (len)
		ft_memcpy(s->ptr + s->len, ss->ptr, len);
	s->len += len;
	s->ptr[s->len] = '\0';
}
