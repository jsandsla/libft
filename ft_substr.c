/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:09:07 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 16:10:02 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*ptr;
	ssize_t	slen;
	ssize_t	len;

	slen = ft_strlen(s);
	len = (slen - start < (ssize_t)n) ? (slen - start) : (ssize_t)(n);
	len = (len < 0) ? (0) : (len);
	ptr = malloc(len + 1);
	if (ptr != NULL)
		ft_strlcpy(ptr, s + (slen < start ? slen : start), len + 1);
	return (ptr);
}
