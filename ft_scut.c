/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:23:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 01:35:40 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_scut(t_s *s, size_t offset, size_t len)
{
	offset = FT_MIN(offset, s->len);
	len = FT_MIN(s->len - offset, len);
	if (offset + len < s->len)
		ft_memcpy(s->ptr + offset,
			s->ptr + offset + len,
			s->len - offset - len);
	s->len -= len;
	s->ptr[s->len] = '\0';
	return (len);
}
