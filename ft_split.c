/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:41:57 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 12:19:52 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_entries(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s += 1;
		if (*s != '\0')
			count += 1;
		while (*s != c && *s != '\0')
			s += 1;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	size_t		count;
	char		**pptr;
	const char	*ptr;

	count = count_entries(s, c);
	pptr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (pptr != NULL)
	{
		count = 0;
		while (*s != '\0')
		{
			while (*s == c && *s != '\0')
				s += 1;
			if (*s != '\0')
			{
				ptr = s;
				while (*s != c && *s != '\0')
					s += 1;
				pptr[count] = malloc((size_t)s - (size_t)ptr + 1);
				ft_strlcpy(pptr[count++], ptr, (size_t)s - (size_t)ptr + 1);
			}
		}
		pptr[count] = NULL;
	}
	return (pptr);
}
