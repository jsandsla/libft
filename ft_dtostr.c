/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:06:56 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 14:20:28 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	reverse(char *s, size_t offset, size_t len)
{
	char	*begin;
	char	*end;
	char	c;

	begin = s + offset;
	end = begin + len - 1;
	while (begin < end)
	{
		c = *begin;
		*begin = *end;
		*end = c;
		begin += 1;
		end -= 1;
	}
}

static	int		pf_double(char *s, int n, double f)
{
	double	power;
	size_t	start;
	int		i;

	i = 0;
	f = ft_fabs(f);
	start = i;
	power = 1.0;
	if (f < power && i < n)
		s[i++] = '0';
	while (f >= power && i < n)
	{
		s[i++] = ((long)(f / power) % 10) + '0';
		power *= 10;
	}
	if (i)
		reverse(s, 0, i);
	return (i);
}

static	int		pf_double_fract(char *s, int n, double f)
{
	double	power;
	int		i;

	i = 0;
	f = ft_fabs(f);
	power = 1.0;
	if (f < power && i < n)
		s[i++] = '0';
	while (f >= power && i < n && i < 6)
	{
		s[i++] = ((long)(f / power) % 10) + '0';
		power *= 10;
	}
	if (i)
		reverse(s, 0, i);
	while (i > 1 && s[i - 1] == '0')
		i -= 1;
	return (i);
}

int				ft_dtostr(char *s, int n, double d)
{
	int		i;
	double	intp;
	double	fract;

	i = 0;
	if (d < 0 && i < n)
		s[i++] = '-';
	fract = ft_modf_erounded(d, &intp, 6);
	if (i < n)
		i += pf_double(s + i, n - i, intp);
	if (i < n && !ft_epsilon(fract, 0.000001))
	{
		s[i++] = '.';
		i += pf_double_fract(s + i, n - i, fract);
	}
	return (i);
}
