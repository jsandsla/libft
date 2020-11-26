/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opvsv4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:24:52 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 12:34:49 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mulvs_v4(t_v4 *l, float r, t_v4 *out)
{
	out->x = l->x * r;
	out->y = l->y * r;
	out->z = l->z * r;
	out->w = l->w * r;
}

void	ft_divvs_v4(t_v4 *l, float r, t_v4 *out)
{
	out->x = l->x / r;
	out->y = l->y / r;
	out->z = l->z / r;
	out->w = l->w / r;
}

void	ft_addvs_v4(t_v4 *l, float r, t_v4 *out)
{
	out->x = l->x + r;
	out->y = l->y + r;
	out->z = l->z + r;
	out->w = l->w + r;
}

void	ft_subvs_v4(t_v4 *l, float r, t_v4 *out)
{
	out->x = l->x - r;
	out->y = l->y - r;
	out->z = l->z - r;
	out->w = l->w - r;
}

void	ft_subsv_v4(float l, t_v4 *r, t_v4 *out)
{
	out->x = l - r->x;
	out->y = l - r->y;
	out->z = l - r->z;
	out->w = l - r->w;
}
