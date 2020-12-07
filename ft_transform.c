/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:04:22 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/30 13:06:29 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_translate_m4(t_m4 m, t_v3 off)
{
	m[3][0] += off[0];
	m[3][1] += off[1];
	m[3][2] += off[2];
}

void			ft_scale_m4(t_m4 m, float s)
{
	m[0][0] *= s;
	m[0][1] *= s;
	m[0][2] *= s;
	m[0][3] *= s;
	m[1][0] *= s;
	m[1][1] *= s;
	m[1][2] *= s;
	m[1][3] *= s;
	m[2][0] *= s;
	m[2][1] *= s;
	m[2][2] *= s;
	m[2][3] *= s;
	m[3][0] *= s;
	m[3][1] *= s;
	m[3][2] *= s;
	m[3][3] *= s;
}