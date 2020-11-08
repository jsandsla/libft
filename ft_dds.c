/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:52:55 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:43:02 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s				ft_dds(t_dds *dds, size_t i)
{
	t_s		s;

	if (i < dds->dd.len)
		ft_sinitm(&s, dds->dd.ptr[i].m);
	else
		ft_sinit(&s, NULL);
	return (s);
}
