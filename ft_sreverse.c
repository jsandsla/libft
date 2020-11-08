/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sreverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:19:00 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/08 22:17:10 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sreverse(t_s *s, size_t offset, size_t len)
{
	char	*begin;
	char	*end;
	char	c;

	offset = FT_MIN(offset, s->len);
	len = FT_MIN(len, s->len - offset);
	begin = (char *)s->m->ptr + offset;
	end = begin + len - 1;
	while (begin < end)
	{
		c = *begin;
		*begin = *end;
		*end = c;
		begin += 1;
		end -= 1;
	}
}
