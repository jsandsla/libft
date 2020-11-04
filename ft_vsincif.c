/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsincif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:42:48 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 20:10:46 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_vsincif(t_vs *vs, char c, size_t offset)
{
	if (ft_vs(vs, 0) == c)
		c = ft_vsinc(vs, offset);
	else
		c = 0;
	return (c);
}
