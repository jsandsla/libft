/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:31:01 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 12:13:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

void			ft_putnbr_fd(int n, int fd)
{
	char	ptr[12];
	size_t	len;

	len = rec_int_print(ptr, n);
	write(fd, ptr, len);
}

void			ft_putnbr(int n)
{
	char	ptr[12];
	size_t	len;

	len = rec_int_print(ptr, n);
	write(STDOUT_FILENO, ptr, len);
}
