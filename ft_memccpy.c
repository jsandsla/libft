/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:22:09 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/29 09:46:41 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	const unsigned char	*end;
	unsigned char		ch;

	ch = (unsigned char)c;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	end = s + n;
	while (s < end && *s != ch)
		*d++ = *s++;
	if (s < end)
		*d++ = *s++;
	else
		d = NULL;
	return (d);
}
