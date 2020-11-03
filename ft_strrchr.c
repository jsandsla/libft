/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:39:09 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/28 21:12:00 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*prev;

	ch = (char)c;
	prev = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
			prev = (char *)s;
		s += 1;
	}
	return (*s == ch ? (char *)s : prev);
}
