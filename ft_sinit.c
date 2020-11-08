/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:05:15 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:08:41 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sinit(t_s *s, char *str)
{
	size_t	len;

	if (str)
		len = ft_strlen(str);
	else
		len = 0;
	s->m = &s->_m;
	ft_minit(s->m, str, len + !!str, len + !!str);
	s->len = len;
	s->max_len = len;
}

void			ft_sinitn(t_s *s, char *str, size_t n)
{
	size_t	len;

	if (str)
		len = ft_strnlen(str, n);
	else
		len = 0;
	s->m = &s->_m;
	ft_minit(s->m, str, len + !!str, str ? FT_MAX(len, n) + 1 : 0);
	s->len = len;
	s->max_len = FT_MAX(len, n);
}

void			ft_sinitm(t_s *s, t_m *m)
{
	s->m = m;
	s->len = m->len ? m->len - 1 : 0;
	s->max_len = m->cap ? m->cap - 1 : 0;
	if (m->ptr)
		s->m->ptr[s->len] = '\0';
}
