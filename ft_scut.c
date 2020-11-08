/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:23:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:37:17 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_scut(t_s *s, size_t offset, size_t len)
{
	offset = FT_MIN(offset, s->len);
	len = FT_MIN(len, s->len - offset);
	ft_mcut(s->m, offset, len);
	s->len -= len;
	s->m->ptr[s->len] = '\0';
	return (len);
}
