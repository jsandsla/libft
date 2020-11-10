/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_daappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:16:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/10 19:50:47 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_daappend(t_da *da, void *elems, size_t count)
{
	t_err	error;
	t_d		d;

	ft_dinitm(&d, da->a.m);
	error = ft_dappend(&d, elems, count);
	return (error);
}
