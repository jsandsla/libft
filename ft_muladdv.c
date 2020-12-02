/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_muladdv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:07:07 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 19:09:53 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mul_add_v3(t_v3 l, t_v3 r, t_v3 add, t_v3 out)
{
	out[0] = l[0] * r[0] + add[0];
	out[1] = l[1] * r[1] + add[1];
	out[2] = l[2] * r[2] + add[2];
}

void	ft_mulvs_add_v3(t_v3 l, float r, t_v3 add, t_v3 out)
{
	out[0] = l[0] * r + add[0];
	out[1] = l[1] * r + add[1];
	out[2] = l[2] * r + add[2];
}

void	ft_mul_add_v4(t_v4 l, t_v4 r, t_v4 add, t_v4 out)
{
	out[0] = l[0] * r[0] + add[0];
	out[1] = l[1] * r[1] + add[1];
	out[2] = l[2] * r[2] + add[2];
	out[3] = l[3] * r[3] + add[3];
}

void	ft_mulvs_add_v4(t_v4 l, float r, t_v4 add, t_v4 out)
{
	out[0] = l[0] * r + add[0];
	out[1] = l[1] * r + add[1];
	out[2] = l[2] * r + add[2];
	out[3] = l[3] * r + add[3];
}
