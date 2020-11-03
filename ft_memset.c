/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:57:36 by tiyez             #+#    #+#             */
/*   Updated: 2020/10/28 10:49:16 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*begin;
	unsigned char	*end;
	unsigned char	ch;

	begin = s;
	end = (unsigned char *)s + n;
	ch = (unsigned char)c;
	while (begin < end)
	{
		*begin = ch;
		begin += 1;
	}
	return (s);
}
