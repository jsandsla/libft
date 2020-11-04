/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_powof2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:16:15 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 23:17:04 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_to_powof2(size_t val)
{
	size_t	powof2;

	if (ft_is_powof2(val))
		powof2 = val;
	else
		powof2 = ft_next_powof2(val);
	return (powof2);
}
