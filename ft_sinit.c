/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:05:15 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 01:14:20 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sinit(t_s *s, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	s->ptr = str;
	s->len = len;
	s->max_len = len;
}

void			ft_sinitn(t_s *s, char *str, size_t n)
{
	size_t	len;

	len = ft_strnlen(s, n);
	s->ptr = str;
	s->len = len;
	s->max_len = FT_MAX(len, n);
}

void			ft_sinitd(t_s *s, t_d *d)
{
	s->ptr = (char *)d->ptr;
	s->max_len = d->reserve_len ? d->max_len : d->max_len - 1;
	s->len = FT_MIN(d->len, s->max_len);
	s->ptr[s->len] = '\0';
}
