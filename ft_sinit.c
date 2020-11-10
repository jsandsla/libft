/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:05:15 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:23:05 by jsandsla         ###   ########.fr       */
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
	ft_minit(s->m, 1, str, len, len + !!str);
}

void			ft_sinitn(t_s *s, char *str, size_t n)
{
	size_t	len;

	if (str)
		len = ft_strnlen(str, n);
	else
		len = 0;
	s->m = &s->_m;
	ft_minit(s->m, 1, str, len, str ? FT_MAX(len, n) + 1 : 0);
}

void			ft_sinitm(t_s *s, t_m *m)
{
	s->m = m;
}
