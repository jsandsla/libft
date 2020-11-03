/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:57:33 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/28 16:03:34 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	sz;

	sz = nmemb * size;
	ptr = malloc(sz);
	if (sz > 0 && ptr != NULL)
	{
		ft_bzero(ptr, sz);
	}
	return (ptr);
}
