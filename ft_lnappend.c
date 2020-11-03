/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:35:57 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 16:11:50 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err	ft_lnappend(t_line *ln, char *str, size_t n)
{
	t_err	error;
	size_t	len;

	error = E_SUCCESS;
	len = ft_strnlen(str, n);
	if (!ln->max_len || ln->len >= ln->max_len)
		error = ft_lnexpand(ln, ln->len + len);
	if (error == E_SUCCESS)
	{
		ft_memcpy(ln->ptr + ln->len, str, len);
		ln->len += len;
		ln->ptr[ln->len] = '\0';
	}
	return (error);
}
