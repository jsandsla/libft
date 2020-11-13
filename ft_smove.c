/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 00:25:47 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/14 00:34:11 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_smove(t_s *s, void *mem, size_t cap)
{
	size_t	len;

	if (cap && cap < s->m->len)
	{
		cap -= 1;
		len = ft_mmove(s->m, mem, cap);
		s->m->cap += 1;
	}
	else
		len = ft_mmove(s->m, mem, cap);
	if (s->m->ptr)
		s->m->ptr[s->m->len] = '\0';
	return (len);
}
