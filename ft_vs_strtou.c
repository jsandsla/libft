/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_strtou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:11:01 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 20:44:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	own_strtou(char *ptr, size_t n, t_uint *out,
	size_t base, const char *sym)
{
	size_t	len;
	t_uint	num;
	char	*ch;

	num = 0;
	len = 0;
	while (len < n && ptr[len] && (ch = ft_strnchr(sym, ptr[len], base)))
	{
		num *= base;
		num += sign * (int)((size_t)ch - (size_t)sym);
		len += 1;
	}
	*out = num;
	return (len);
}

size_t			ft_vs_strtou(t_vs *vs, t_uint *out, int base, const char *sym)
{
	char	*ptr;
	size_t	n;

	n = 0;
	if (base >= 2 && base <= 16)
	{
		ptr = vs->ptr + vs->offset;
		n = vs->len - vs->offset;
		n = own_strtou(ptr, n, out, base, sym);
	}
	return (n);
}
