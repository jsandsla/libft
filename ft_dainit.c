/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dainit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:10:25 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:38:13 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dainit(t_da *da, size_t sz, void *elems, size_t len,
	size_t max_len)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
	{
		ft_ainit(&da->a, sz, 0, 0, 0);
		if (elems)
			error = ft_daappend(da, elems, len);
		else if (max_len)
			error = ft_daexpand(da, max_len);
	}
	return (error);
}

t_err			ft_dainitm(t_da *da, size_t sz, t_m *m)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (sz)
		ft_ainitm(&da->a, sz, m);
	return (error);
}
