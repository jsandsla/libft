/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dds_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:20:33 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/09 01:16:39 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_dds_len(t_dds *dds)
{
	size_t	len;
	size_t	l;
	size_t	i;

	len = 0;
	while (i < dds->dd.len)
	{
		l = dds->dd.ptr[i].m->len;
		len += l > 0 ? l - 1 : 0;
		i += 1;
	}
	return (len);
}
