/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:44:14 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:06:55 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsappend(t_ds *str, char *mem, size_t n)
{
	t_err	error;

	error = ft_dappendc(&str->d, (t_byte *)mem, 0, n);
	if (error)
	{
		str->ptr = (char *)str->d.ptr;
		str->len = str->d.len;
		str->ptr[str->len] = '\0';
	}
	return (error);
}
