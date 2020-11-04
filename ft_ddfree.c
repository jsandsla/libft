/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:50:43 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 13:58:45 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ddfree(t_dd *dd)
{
	size_t	i;

	i = 0;
	while (i < dd->len)
	{
		ft_dfree(&dd->ptr[i]);
		i += 1;
	}
	ft_dafree(dd->da);
	dd->len = 0;
	dd->ptr = 0;
}
