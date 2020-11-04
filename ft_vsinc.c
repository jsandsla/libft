/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsinc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:00:36 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/04 19:42:32 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_vsinc(t_vs *vs, size_t offset)
{
	char	prev;

	prev = ft_vs(vs, 0);
	offset = FT_MIN(offset, vs->len - vs->offset);
	vs->offset += offset;
	return (prev);
}
