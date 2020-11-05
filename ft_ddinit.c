/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:55:29 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 13:56:58 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddinit(t_dd *dd)
{
	t_err	error;

	dd->da = &dd->_da;
	error = ft_dainit(dd->da, sizeof(t_d), 0, 0);
	if (error == E_OK)
	{
		dd->len = 0;
		dd->ptr = 0;
	}
	return (error);
}
