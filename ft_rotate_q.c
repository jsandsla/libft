/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_q.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:50:16 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:24:21 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_rotate_qv3(t_v3 in, t_quat q, t_v3 out)
{
	t_quat	p;
	t_v3	u;
	t_v3	v[3];
	float	s;
	float	scl;

	ft_copy_v3(in, v[0]);
	ft_normalize_quat_to(q, p);
	ft_imag_quat(p, u);
	s = ft_real_quat(p);
	scl = 2 * ft_dot_v3(u, v[0]);
	ft_mulvs_v3(u, scl, v[1]);
	scl = s * s - ft_dot_v3(u, u);
	ft_mulvs_v3(v[0], scl, v[2]);
	ft_add_v3(v[1], v[2], v[1]);
	ft_cross_v3_to(v[0], u, v[2]);
	scl = 2 * s;
	ft_mulvs_v3(v[2], scl, v[2]);
	ft_add_v3(v[1], v[2], out);
}

void			ft_rotate_qm4(t_m4 m, t_quat q, t_m4 out)
{
	t_m4	rot;

	ft_quat_to_m4(q, rot);
	ft_mul_m4_to(m, rot, out);
}

void			ft_rotate_qm4_at(t_m4 m, t_v3 pivot, t_quat q, t_m4 out)
{
	t_v3	pivot_neg;

	ft_subsv_v3(0, pivot, pivot_neg);
	ft_translate_m4(m, pivot);
	ft_rotate_qm4(m, q, out);
	ft_translate_m4(m, pivot_neg);
}
