/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:37:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 23:25:14 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsinit(t_ds *ds, char *mem, size_t len)
{
	t_err	error;

	ds->d = &ds->_d;
	error = ft_dinitex(ds->d, mem, len, 1);
	if (error == E_OK)
	{
		ds->len = 0;
		ds->ptr = (char *)ds->d->ptr;
	}
	return (error);
}
