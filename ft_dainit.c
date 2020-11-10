/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dainit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:10:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:48:09 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dainit(t_da *da, size_t sz, void *p, size_t len, size_t cp)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		ft_ainit(&da->a, sz, NULL, 0, 0);
		if (p)
			error = ft_daappend(da, p, len);
		else if (cp)
			error = ft_daexpand(da, cp);
		else
			error = E_OK;
	}
	return (error);
}

void			ft_dainitm(t_da *da, t_m *m)
{
	ft_ainitm(&da->a, m);
}
