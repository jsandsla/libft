/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:22:58 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 23:24:36 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dinit(t_d *d, t_byte *mem, size_t len)
{
	t_err	error;

	error = ft_dinitex(d, mem, len, 0);
	return (error);
}
