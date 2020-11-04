/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dainitlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:32:57 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:32:59 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dainitlink(t_da *da, size_t sz, t_d *d)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		da->sz = sz;
		error = ft_dalink(da, d);
	}
	return (error);
}
