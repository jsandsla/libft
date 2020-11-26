/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:19:37 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 17:14:43 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define M(l1,l2,r1,r2) l->r##l1.l2 * r->r##r1.r2

void	ft_mul_m4_to(t_m4 *l, t_m4 *r, t_m4 *out)
{
	out->r0.x = M(0,x,0,x) + M(0,y,1,x) + M(0,z,2,x) + M(0,w,3,x);
	out->r0.y = M(0,x,0,y) + M(0,y,1,y) + M(0,z,2,y) + M(0,w,3,y);
	out->r0.z = M(0,x,0,z) + M(0,y,1,z) + M(0,z,2,z) + M(0,w,3,z);
	out->r0.w = M(0,x,0,w) + M(0,y,1,w) + M(0,z,2,w) + M(0,w,3,w);
	out->r1.x = M(1,x,0,x) + M(1,y,1,x) + M(1,z,2,x) + M(1,w,3,x);
	out->r1.y = M(1,x,0,y) + M(1,y,1,y) + M(1,z,2,y) + M(1,w,3,y);
	out->r1.z = M(1,x,0,z) + M(1,y,1,z) + M(1,z,2,z) + M(1,w,3,z);
	out->r1.w = M(1,x,0,w) + M(1,y,1,w) + M(1,z,2,w) + M(1,w,3,w);
	out->r2.x = M(2,x,0,x) + M(2,y,1,x) + M(2,z,2,x) + M(2,w,3,x);
	out->r2.y = M(2,x,0,y) + M(2,y,1,y) + M(2,z,2,y) + M(2,w,3,y);
	out->r2.z = M(2,x,0,z) + M(2,y,1,z) + M(2,z,2,z) + M(2,w,3,z);
	out->r2.w = M(2,x,0,w) + M(2,y,1,w) + M(2,z,2,w) + M(2,w,3,w);
	out->r3.x = M(3,x,0,x) + M(3,y,1,x) + M(3,z,2,x) + M(3,w,3,x);
	out->r3.y = M(3,x,0,y) + M(3,y,1,y) + M(3,z,2,y) + M(3,w,3,y);
	out->r3.z = M(3,x,0,z) + M(3,y,1,z) + M(3,z,2,z) + M(3,w,3,z);
	out->r3.w = M(3,x,0,w) + M(3,y,1,w) + M(3,z,2,w) + M(3,w,3,w);
}

void	ft_mul_m4rot_to(t_m3 *l, t_m4 *r, t_m4 *out)
{
	out->r0.x = M(0,x,0,x) + M(0,y,1,x) + M(0,z,2,x);
	out->r0.y = M(0,x,0,y) + M(0,y,1,y) + M(0,z,2,y);
	out->r0.z = M(0,x,0,z) + M(0,y,1,z) + M(0,z,2,z);
	out->r0.w = M(0,x,0,w) + M(0,y,1,w) + M(0,z,2,w);
	out->r1.x = M(1,x,0,x) + M(1,y,1,x) + M(1,z,2,x);
	out->r1.y = M(1,x,0,y) + M(1,y,1,y) + M(1,z,2,y);
	out->r1.z = M(1,x,0,z) + M(1,y,1,z) + M(1,z,2,z);
	out->r1.w = M(1,x,0,w) + M(1,y,1,w) + M(1,z,2,w);
	out->r2.x = M(2,x,0,x) + M(2,y,1,x) + M(2,z,2,x);
	out->r2.y = M(2,x,0,y) + M(2,y,1,y) + M(2,z,2,y);
	out->r2.z = M(2,x,0,z) + M(2,y,1,z) + M(2,z,2,z);
	out->r2.w = M(2,x,0,w) + M(2,y,1,w) + M(2,z,2,w);
	out->r3.x = r->r3.x;
	out->r3.y = r->r3.y;
	out->r3.z = r->r3.z;
	out->r3.w = r->r3.w;
}

#undef M
#define M(l1,r1,r2) l->l1 * r->r##r1.r2

void	ft_mul_vm4_to(t_v4 *l, t_m4 *r, t_v4 *out)
{
	out->x = M(x,0,x) + M(y,1,x) + M(z,2,x) + M(w,3,x);
	out->y = M(x,0,y) + M(y,1,y) + M(z,2,y) + M(w,3,y);
	out->z = M(x,0,z) + M(y,1,z) + M(z,2,z) + M(w,3,z);
	out->w = M(x,0,w) + M(y,1,w) + M(z,2,w) + M(w,3,w);
}

#undef M

void	ft_transpose_m4(t_m4 *l)
{
	t_m4	m4;

	ft_transpose_m4_to(l, &m4);
	*l = m4;
}

void	ft_transpose_m4_to(t_m4 *l, t_m4 *out)
{
	out->r0.x = l->r0.x;
	out->r1.x = l->r0.y;
	out->r2.x = l->r0.z;
	out->r3.x = l->r0.w;
	out->r0.y = l->r1.x;
	out->r1.y = l->r1.y;
	out->r2.y = l->r1.z;
	out->r3.y = l->r1.w;
	out->r0.z = l->r2.x;
	out->r1.z = l->r2.y;
	out->r2.z = l->r2.z;
	out->r3.z = l->r2.w;
	out->r0.w = l->r3.x;
	out->r1.w = l->r3.y;
	out->r2.w = l->r3.z;
	out->r3.w = l->r3.w;
}
