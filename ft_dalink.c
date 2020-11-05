/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dalink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:34:07 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:29:34 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dalink(t_da *da, size_t sz, t_d *d)
{
	t_err	error;

	error = E_OK;
	if (d != NULL)
	{
		da->d = d;
		ft_ainitd(&da->a, sz, d);
	}
	else
		error = ft_dalink(da, sz, &da->_d);
	return (error);
}
