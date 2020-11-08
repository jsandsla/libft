/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsexpand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:05:18 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:06:34 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsexpand(t_ds *ds, size_t required)
{
	t_d		d;
	t_err	error;

	ft_dinitm(&d, ds->s.m);
	error = ft_dexpand(&d, required);
	if (error == E_OK)
		ft_sinitm(&ds->s, d.m);
	return (error);
}
