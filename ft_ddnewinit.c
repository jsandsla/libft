/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddnewinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:01:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 23:20:51 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_ddnewinit(t_dd *dd, t_d **ppd, t_byte *mem, size_t len)
{
	t_err	error;

	error = ft_ddnewinitex(dd, ppd, mem, len, 0);
	return (error);
}
