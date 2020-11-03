/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:50:20 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/28 17:57:35 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const void	*end1;

	end1 = (unsigned char *)s1 + n;
	while (s1 < end1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
	}
	return (s1 < end1 ?
		(int)*(unsigned char *)s1 - (int)*(unsigned char *)s2 : 0);
}
