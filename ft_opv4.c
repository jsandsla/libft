/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opv4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:23:26 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 12:34:50 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mul_v4(t_v4 *l, t_v4 *r, t_v4 *out)
{
	out->x = l->x * r->x;
	out->y = l->y * r->y;
	out->z = l->z * r->z;
	out->w = l->w * r->w;
}

void	ft_div_v4(t_v4 *l, t_v4 *r, t_v4 *out)
{
	out->x = l->x / r->x;
	out->y = l->y / r->y;
	out->z = l->z / r->z;
	out->w = l->w / r->w;
}

void	ft_add_v4(t_v4 *l, t_v4 *r, t_v4 *out)
{
	out->x = l->x + r->x;
	out->y = l->y + r->y;
	out->z = l->z + r->z;
	out->w = l->w + r->w;
}

void	ft_sub_v4(t_v4 *l, t_v4 *r, t_v4 *out)
{
	out->x = l->x - r->x;
	out->y = l->y - r->y;
	out->z = l->z - r->z;
	out->w = l->w - r->w;
}
