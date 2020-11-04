/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:34:56 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 20:36:54 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnchr(const char *s, int c, size_t n)
{
	char	ch;

	ch = (char)c;
	while (n > 0 && *s != '\0' && *s != ch)
	{
		s += 1;
		n -= 1;
	}
	return (n > 0 && *s == ch ? (char *)s : NULL);
}
