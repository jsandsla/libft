/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:57:10 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 15:29:07 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mul_m3_to(t_m3 *l, t_m3 *r, t_m3 *out)
{
	out->r0.x = l->r0.x * r->r0.x + l->r0.y * r->r1.x + l->r0.z * r->r2.x;
	out->r0.y = l->r0.x * r->r0.y + l->r0.y * r->r1.y + l->r0.z * r->r2.y;
	out->r0.z = l->r0.x * r->r0.z + l->r0.y * r->r1.z + l->r0.z * r->r2.z;
	out->r1.x = l->r1.x * r->r0.x + l->r1.y * r->r1.x + l->r1.z * r->r2.x;
	out->r1.y = l->r1.x * r->r0.y + l->r1.y * r->r1.y + l->r1.z * r->r2.y;
	out->r1.z = l->r1.x * r->r0.z + l->r1.y * r->r1.z + l->r1.z * r->r2.z;
	out->r2.x = l->r2.x * r->r0.x + l->r2.y * r->r1.x + l->r2.z * r->r2.x;
	out->r2.y = l->r2.x * r->r0.y + l->r2.y * r->r1.y + l->r2.z * r->r2.y;
	out->r2.z = l->r2.x * r->r0.z + l->r2.y * r->r1.z + l->r2.z * r->r2.z;
}

void	ft_mul_vm3_to(t_v3 *l, t_m3 *r, t_v3 *out)
{
	out->x = l->x * r->r0.x + l->y * r->r1.x + l->z * r->r2.x;
	out->y = l->x * r->r0.y + l->y * r->r1.y + l->z * r->r2.y;
	out->z = l->x * r->r0.z + l->y * r->r1.z + l->z * r->r2.z;
}

void	ft_transpose_m3(t_m3 *l)
{
	t_m3	t;

	t.r1.x = l->r0.y;
	t.r2.x = l->r0.z;
	t.r0.y = l->r1.x;
	t.r2.y = l->r1.z;
	t.r0.z = l->r2.x;
	t.r1.z = l->r2.y;
	l->r1.x = t.r1.x;
	l->r2.x = t.r2.x;
	l->r0.y = t.r0.y;
	l->r2.y = t.r2.y;
	l->r0.z = t.r0.z;
	l->r1.z = t.r1.z;
}

void	ft_transpose_m3_to(t_m3 *l, t_m3 *out)
{
	out->r0.x = l->r0.x;
	out->r1.x = l->r0.y;
	out->r2.x = l->r0.z;
	out->r0.y = l->r1.x;
	out->r1.y = l->r1.y;
	out->r2.y = l->r1.z;
	out->r0.z = l->r2.x;
	out->r1.z = l->r2.y;
	out->r2.z = l->r2.z;
}
