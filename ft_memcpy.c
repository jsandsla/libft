/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:15:05 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 14:02:40 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	const unsigned char	*end;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	end = s + n;
	while (s < end)
	{
		*d = *s;
		d += 1;
		s += 1;
	}
	return (dest);
}
