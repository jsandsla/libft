/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:07:02 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/28 10:44:47 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*begin;
	unsigned char	*end;

	begin = (unsigned char *)s;
	end = (unsigned char *)s + n;
	while (begin < end)
	{
		*begin = 0;
		begin += 1;
	}
}
