/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:03:51 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/29 12:39:53 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	rec_print(char *out, long long unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 9)
		i = rec_print(out, n / 10);
	out[i] = (n % 10) + '0';
	return (i + 1);
}

static	size_t	rec_int_print(char *out, int n)
{
	size_t	i;

	if (n < 0)
	{
		*out = '-';
		i = rec_print(out + 1, (long long unsigned)-(long long)n);
		i += 1;
	}
	else
		i = rec_print(out, n);
	out[i] = '\0';
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ptr;

	ptr = malloc(12);
	if (ptr != NULL)
		rec_int_print(ptr, n);
	return (ptr);
}
