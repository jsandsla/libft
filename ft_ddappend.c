/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:55:03 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/03 22:51:02 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddappend(t_dd *dd, t_d *d)
{
	t_err	error;
	t_d		*pd;

	error = ft_ddnew(dd, &pd);
	if (error == E_OK)
		*pd = *d;
	return (error);
}
