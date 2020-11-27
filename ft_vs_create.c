/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:17 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 15:36:24 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vs			ft_vs_create(const char *str, size_t len)
{
	t_vs	vs;

	vs.ptr = str;
	vs.len = ft_strnlen(str, len);
	vs.offset = 0;
	return (vs);
}

t_vs			ft_vs_create_str(const char *str)
{
	t_vs	vs;

	vs.ptr = str;
	vs.len = ft_strlen(str);
	vs.offset = 0;
	return (vs);
}

t_vs			ft_vs_create_s(t_s *s, size_t offset, size_t len)
{
	t_vs	vs;

	offset = FT_MIN(offset, s->m->len);
	vs.ptr = (char *)s->m->ptr + offset;
	vs.len = FT_MIN(len, s->m->len - offset);
	vs.offset = 0;
	return (vs);
}
