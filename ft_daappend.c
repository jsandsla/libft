/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:16:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:28:38 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_daappend(t_da *da, void *elems, size_t count)
{
	t_err	error;

	error = ft_dappend(da->d, elems, count * da->a.sz);
	if (error == E_OK)
		ft_ainitd(&da->a, da->a.sz, da->d);
	return (error);
}
