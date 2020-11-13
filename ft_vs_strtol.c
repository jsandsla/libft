/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs_strtol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:11:01 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/13 21:24:01 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		own_strtol(const char *ptr, size_t n, size_t base,
	const char *sym)
{
	size_t	len;
	int		num;
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
	return (num);
}

size_t			ft_vs_strtol(t_vs *vs, int *out, int base, const char *sym)
{
	const char	*ptr;
	size_t		n;
	size_t		i;

	i = 0;
	if (base >= 2 && base <= 16)
	{
		ptr = vs->ptr + vs->offset;
		n = vs->len - vs->offset;
		*out = own_strtol(ptr, n, base, sym);
		i = (*ptr == '-' || *ptr == '+');
		while (i < n && ft_strnchr(sym, ptr[i], base))
			i += 1;
	}
	return (i);
}
