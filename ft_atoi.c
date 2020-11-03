/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:35:14 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/29 10:57:37 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\v'
		|| ch == '\f');
}

int			ft_atoi(const char *nptr)
{
	int				sign;
	long long int	r;
	int				num;

	while (is_space(*nptr))
		nptr += 1;
	sign = *nptr == '-' ? -1 : 1;
	if (*nptr == '-' || *nptr == '+')
		nptr += 1;
	r = 1;
	num = 0;
	while (nptr[num] >= '0' && nptr[num] <= '9')
	{
		r *= 10;
		num += 1;
	}
	num = 0;
	r /= 10;
	while (r > 0)
	{
		num += r * (sign < 0 ? -(int)(*nptr - '0') : (int)(*nptr - '0'));
		r /= 10;
		nptr += 1;
	}
	return (num);
}
