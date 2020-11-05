/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vscreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:17 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 15:01:43 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vs			ft_vscreate(const char *str, size_t len)
{
	t_vs	vs;

	vs.ptr = str;
	vs.len = ft_strnlen(str, len);
	vs.offset = 0;
	return (vs);
}

t_vs			ft_vscreatestr(const char *str)
{
	t_vs	vs;

	vs.ptr = str;
	vs.len = ft_strlen(str);
	vs.offset = 0;
	return (vs);
}

t_vs			ft_vscreateds(t_ds *ds, size_t offset, size_t len)
{
	t_vs	vs;

	vs = ft_vscreates(&ds->s, offset, len);
	return (vs);
}

t_vs			ft_vscreates(t_s *s, size_t offset, size_t len)
{
	t_vs	vs;

	offset = FT_MIN(offset, s->len);
	vs.ptr = s->ptr + offset;
	vs.len = FT_MIN(s->len - offset, len);
	vs.offset = 0;
	return (vs);
}
