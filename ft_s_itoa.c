/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 08:35:33 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/24 13:20:31 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_s_utoa(t_s *s, size_t n, unsigned base, const char *sym)
{
	size_t	i;

	i = 0;
	if (n > 9)
		i = ft_s_utoa(s, n / base, base, sym);
	ft_sappendc(s, sym[n % base]);
	return (i + 1);
}

size_t	ft_s_itoa(t_s *s, ssize_t n, unsigned base, const char *sym)
{
	size_t	i;

	if (n < 0)
	{
		ft_sappend(s, "-");
		i = ft_s_utoa(s, (size_t)-n, base, sym);
		i += 1;
	}
	else
		i = ft_s_utoa(s, n, base, sym);
	return (i);
}

size_t	ft_s_unsigned(t_s *s, size_t val)
{
	size_t	len;

	len = ft_s_utoa(s, val, 10, "0123456789");
	return (len);
}

size_t	ft_s_signed(t_s *s, ssize_t val)
{
	size_t	len;

	len = ft_s_itoa(s, val, 10, "0123456789");
	return (len);
}
