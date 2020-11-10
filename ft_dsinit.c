/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:37:59 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 00:18:03 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dsinit(t_ds *ds, char *str)
{
	t_err	error;

	error = E_OK;
	ft_sinitn(&ds->s, 0, 0);
	if (str)
		error = ft_dsappendstr(ds, str);
	return (error);
}

t_err			ft_dsinitn(t_ds *ds, char *str, size_t len)
{
	t_err	error;

	error = E_OK;
	ft_sinitn(&ds->s, 0, 0);
	if (str)
		error = ft_dsappend(ds, str, len);
	return (error);
}

void			ft_dsinitm(t_ds *ds, t_m *m)
{
	ft_sinitm(&ds->s, m);
}
