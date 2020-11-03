/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:46:33 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/31 23:05:26 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	char	*res;
	size_t	litlen;

	res = (char *)big;
	if (*lit != '\0')
	{
		res = NULL;
		litlen = ft_strlen(lit);
		while (*big != '\0' && res == NULL && len >= litlen)
		{
			if (*big == *lit && ft_strncmp(big, lit, litlen) == 0)
				res = (char *)big;
			len -= 1;
			big += 1;
		}
	}
	return (res);
}
