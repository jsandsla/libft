/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_strtol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:11:01 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 20:42:16 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	own_strtol(char *ptr, size_t n, t_uint *out,
	size_t base, const char *sym)
{
	size_t	len;
	t_uint	num;
	int		sign;
	char	*ch;

	num = 0;
	len = (*ptr == '-' || *ptr == '+');
	sign = 1;
	if (*ptr == '-')
		sign = -1;
	while (len < n && ptr[len] && (ch = ft_strnchr(sym, ptr[len], base)))
	{
		num *= base;
		num += sign * (int)((size_t)ch - (size_t)sym);
		len += 1;
	}
	*out = num;
	return (len);
}

size_t			ft_vs_strtol(t_vs *vs, t_uint *out, int base, const char *sym)
{
	char	*ptr;
	size_t	n;

	n = 0;
	if (base >= 2 && base <= 16)
	{
		ptr = vs->ptr + vs->offset;
		n = vs->len - vs->offset;
		n = own_strtol(ptr, n, out, base, sym);
	}
	return (n);
}
