/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:37:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:06:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsinit(t_ds *str, char *mem, size_t max_len)
{
	t_err	error;

	error = ft_dinit(&str->d, 0, 0);
	if (error == E_OK)
	{
		str->d.reserve_len = 1;
		str->len = 0;
		if (mem)
			error = ft_dsappend(str, mem, max_len);
		else if (max_len)
			error = ft_dexpand(&str->d, max_len);
		str->ptr = (char *)str->d.ptr;
	}
	return (error);
}
