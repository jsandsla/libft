/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daexpand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:42:49 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 00:10:51 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_daexpand(t_da *da, size_t required)
{
	t_err	error;
	t_d		d;

	ft_dinitm(&d, da->a.m);
	error = ft_dexpand(&d, required);
	if (error == E_OK)
		ft_ainitm(&da->a, da->a.sz, d.m);
	return (error);
}
