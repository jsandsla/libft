/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imag_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:30:21 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/01 14:32:29 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

float			ft_real_quat(t_quat q)
{
	return (q[3]);
}

void			ft_imag_quat(t_quat q, t_v3 out)
{
	out[0] = q[0];
	out[1] = q[1];
	out[2] = q[2];
}

void			ft_imag_normalized_quat(t_quat q, t_v3 out)
{
	out[0] = q[0];
	out[1] = q[1];
	out[2] = q[2];
	ft_ext_normalize_v3(out);
}

float			ft_imag_norm_quat(t_quat q)
{
	float	norm;

	norm = sqrtf(ft_dot_v3(q, q));
	return (norm);
}
