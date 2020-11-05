/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddsinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:01:56 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 16:07:24 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddsinit(t_dds *dds, size_t rate)
{
	t_err	error;

	error = E_INVALID_PARAMETER;
	if (rate > 0)
	{
		dds->rate = rate;
		dds->dd = &dds->_dd;
		error = ft_ddinit(dds->dd);
	}
	return (error);
}
