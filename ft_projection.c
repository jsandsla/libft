/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:37:03 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:19:33 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_perspective(float aspect, float far, float fov, t_m4 out)
{
	float	near;
	float	b;
	float	r;
	float	p;

	near = 0.1f;
	p = near * tanf(FT_RAD(fov) * 0.5f);
	if (aspect > 0)
	{
		b = p;
		r = p * aspect;
	}
	else
	{
		aspect = 1 / aspect;
		b = p * aspect;
		r = p;
	}
	ft_bzero(out, sizeof(t_m4));
	out[0][0] = near / r;
	out[1][1] = -near / b;
	out[2][3] = -1;
	out[2][2] = (far + near) / (near - far);
	out[3][2] = 2 * far * near / (near - far);
}
