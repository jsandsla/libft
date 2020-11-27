/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:58:35 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 11:00:41 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset4(void *mem, unsigned int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned int *)mem)[i] = c;
		i += 1;
	}
	return (mem);
}
