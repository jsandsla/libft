/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:25:40 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/28 17:39:56 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			direction;
	const void	*end;
	void		*d;

	d = dest;
	if (dest != src)
	{
		direction = (dest < src) * 2 - 1;
		end = (unsigned char *)src + (long long int)n * direction;
		if (direction < 0)
		{
			end = (unsigned char *)src - 1;
			src = (unsigned char *)src + (long long int)n - 1;
			dest = (unsigned char *)dest + (long long int)n - 1;
		}
		while (src != end)
		{
			*(unsigned char *)dest = *(unsigned char *)src;
			dest = (unsigned char *)dest + direction;
			src = (unsigned char *)src + direction;
		}
	}
	return (d);
}
