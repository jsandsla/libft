/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:08:09 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/05 14:23:58 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_vs(t_vs *vs, size_t offset)
{
	offset = FT_MIN(offset, vs->len - vs->offset);
	return (vs->offset + offset == vs->len ? '\0' : vs->ptr[vs->offset + offset]);
}
