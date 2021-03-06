/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_strtou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:11:01 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/24 12:00:44 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_uint	own_strtou(const char *ptr, size_t n, size_t base,
	const char *sym)
{
	size_t	len;
	t_uint	num;
	char	*ch;

	num = 0;
	len = 0;
	while (len < n && ptr[len] && (ch = ft_strnchr(sym, ptr[len], base)))
	{
		num *= base;
		num += (t_uint)((size_t)ch - (size_t)sym);
		len += 1;
	}
	return (num);
}

size_t			ft_vs_strtou(t_vs *vs, t_uint *out, int base, const char *sym)
{
	const char	*ptr;
	size_t		n;
	size_t		i;

	i = 0;
	if (base >= 2 && base <= 16)
	{
		ptr = vs->ptr + vs->offset;
		n = vs->len - vs->offset;
		*out = own_strtou(ptr, n, base, sym);
		while (i < n && ft_strnchr(sym, ptr[i], base))
			i += 1;
	}
	return (i);
}
