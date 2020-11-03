/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:18:04 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/29 10:16:04 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = ft_strnlen(dest, size);
	if (size && i < size - 1)
	{
		i += ft_strlcpy(dest + i, src, size - i);
	}
	else
	{
		i += ft_strlen(src);
	}
	return (i);
}
