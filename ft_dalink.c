/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dalink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:34:07 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 23:45:50 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dalink(t_da *da, t_d *d)
{
	t_err	error;

	error = E_OK;
	if (d != NULL)
	{
		da->d = d;
		if (d->len && d->ptr)
		{
			da->ptr = d->ptr;
			da->len = d->len / da->sz;
		}
	}
	else
		error = ft_dalink(da, &da->_d);
	return (error);
}
