/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:52:55 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 15:56:15 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s				ft_dds(t_dds *dds, size_t i)
{
	t_ds	ds;
	t_err	error;

	error = E_OUT_OF_BOUNDS;
	if (i < dds->dd->len)
		error = ft_dsinitd(&ds, &dds->dd->ptr[i]);
	if (error != E_OK)
		ft_dsinit(&ds, 0, 0);
	return (ds.s);
}
