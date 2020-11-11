/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dds_spread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:12:17 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/11 17:55:16 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_err			ft_dds_spread(t_dds *dds, char c, size_t len)
{
	t_err	error;

	error = E_OK;
	while (error == E_OK && len > 0)
	{
		error = ft_ddsappendraw(dds, &c, 1);
		len -= 1;
	}
	return (error);
}

