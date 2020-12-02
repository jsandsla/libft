/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usequat2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:34:33 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 18:12:36 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void			ft_lerp_quat(t_quat l, t_quat r, float t, t_quat out)
{
	ft_lerp_v4(l, r, t, out);
}

static	void	calc_slerp(t_quat q1, t_quat q2, float use[5], t_quat out)
{
	use[2] = acosf(use[0]);
	use[3] = sinf((1 - use[4]) * use[2]);
	ft_mulvs_v4(q1, use[3], q1);
	use[3] = sinf(use[4] * use[2]);
	ft_mulvs_v4(q2, use[3], q2);
	ft_add_v4(q1, q2, q1);
	use[3] = 1 / use[1];
	ft_mulvs_v4(q1, use[3], out);
}

void			ft_slerp_quat(t_quat l, t_quat r, float t, t_quat out)
{
	t_quat	q1;
	t_quat	q2;
	float	use[5];

	use[4] = t;
	use[0] = ft_dot_v4(l, r);
	if (ft_fabsf(use[0]) >= 1)
		ft_copy_v4(l, out);
	else
	{
		ft_copy_v4(l, q1);
		if (use[0] < 0)
		{
			ft_subsv_v4(0, q1, q1);
			use[0] = -use[0];
		}
		use[1] = sqrtf(1 - use[0] * use[0]);
		if (ft_fabsf(use[1]) < 0.001f)
			ft_lerp_v4(l, r, t, out);
		else
		{
			ft_copy_v4(r, q2);
			calc_slerp(q1, q2, use, out);
		}
	}
}

void			ft_lookat_quat(t_v3 pos, t_quat q, t_m4 out)
{
	ft_quat_to_m4(q, out);
	ft_mul_v3m4(out, pos, 1, out[3]);
	out[3][0] = -out[3][0];
	out[3][1] = -out[3][1];
	out[3][2] = -out[3][2];
}
