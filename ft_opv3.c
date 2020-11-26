/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opv3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:38:48 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 11:39:52 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mul_v3(t_v3 *l, t_v3 *r, t_v3 *out)
{
	out->x = l->x * r->x;
	out->y = l->y * r->y;
	out->z = l->z * r->z;
}

void	ft_div_v3(t_v3 *l, t_v3 *r, t_v3 *out)
{
	out->x = l->x / r->x;
	out->y = l->y / r->y;
	out->z = l->z / r->z;
}

void	ft_add_v3(t_v3 *l, t_v3 *r, t_v3 *out)
{
	out->x = l->x + r->x;
	out->y = l->y + r->y;
	out->z = l->z + r->z;
}

void	ft_sub_v3(t_v3 *l, t_v3 *r, t_v3 *out)
{
	out->x = l->x - r->x;
	out->y = l->y - r->y;
	out->z = l->z - r->z;
}
